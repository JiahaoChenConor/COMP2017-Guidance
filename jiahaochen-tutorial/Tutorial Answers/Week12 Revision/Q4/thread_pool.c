#include "thread_pool.h"


// This return the address of threads
struct thread_pool* thread_pool_new(size_t n){
    thread_pool* pool = (thread_pool*) malloc(sizeof(thread_pool));


    pool -> shutdown = 0;
    pool -> max_threads = n;
    pool -> threads_id = (pthread_t *) malloc(sizeof(pthread_t) * n);
 
    pool -> queue_head = NULL;
    pthread_cond_init(&(pool -> queue_avilable), NULL);
    pthread_mutex_init(&(pool -> queue_lock), NULL);
    

    // create threads
    for (size_t i = 0; i < n; i++){
        // At this stage, all threads are executing function thread_pool_work, since there is a mutex and wait, these threads will wait until the queue is avaliable.
        pthread_create((pool->threads_id + i), NULL, thread_pool_work, (void*) pool);
    
    }

    return pool;
}

// This is just add a new item to queue
// The first argument is function pointer which print the info of this job
// The second argumnet is data 
struct thread_job* thread_job_new(void(*fn)(void*), void* data){
    // use the funtcion pointer to print some info
    fn(data);

    // create new task
    thread_job* new_job = (thread_job *)malloc(sizeof(thread_job));
    new_job->fp = thread_pool_work;
    new_job->args = data;
    new_job->next = NULL;

    return new_job;
}

// put the job into the queue => producer
void thread_pool_execute(struct thread_pool* pool, struct thread_job* job){

    pthread_mutex_lock(&(pool->queue_lock));

    thread_job * cur = pool->queue_head;
    
    /* enqueue task */

    // The queue is empty
    if (!cur){
        pool->queue_head = job;
    }else{
        // The queue is not empty, enqueue the job
        while (cur->next){
            cur = cur->next;
        }
        // until cur is the last job since its next is NULL
        cur->next = job;
    }

    pthread_cond_signal(&(pool->queue_avilable));
    pthread_mutex_unlock(&(pool->queue_lock));

    return;
}

// consumer
void* thread_pool_work(void* arg){
    thread_pool* pool = (thread_pool *)arg;

    pthread_mutex_lock(&(pool->queue_lock));

    while (1){
        
        // while queue is not empty
        while (!(pool->queue_head) && !(pool->shutdown)){
            pthread_cond_wait(&(pool->queue_avilable), &(pool->queue_lock));
        }
        

        // If pool has shutdown, then relase the mutex firstly and then exit thread
        if (pool->shutdown){
            pthread_mutex_unlock(&(pool->queue_lock));
            pthread_exit(NULL);
        }

        // Else dequeue a job
        thread_job* dequeued_job = pool->queue_head;
        pool->queue_head = pool->queue_head->next;
        pthread_mutex_unlock(&(pool->queue_lock));

        // thread_pool_work(dequeued_job->args);
        free(dequeued_job);
    }
    return NULL;
}


void thread_job_destroy(struct thread_job* j){
    free(j);
}

void thread_pool_destroy(struct thread_pool* pool){
    if (pool->shutdown){
        return;
    }

    pool->shutdown = 1;

    pthread_mutex_lock(&(pool->queue_lock));
    pthread_cond_signal(&(pool->queue_avilable));
    pthread_mutex_unlock(&(pool->queue_lock));

    for (size_t i = 0; i < pool->max_threads; i++){
        pthread_join(*(pool->threads_id + i), NULL);
    }
    free(pool->threads_id);

    // free queue
    // thread_job* tmp;
    // while (pool->queue_head){
    //     tmp = pool->queue_head;
    //     pool->queue_head = pool->queue_head->next;
    //     free(tmp);
    // }

    thread_job* tmp;
    thread_job* cur = pool->queue_head;
    while (cur->next){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

