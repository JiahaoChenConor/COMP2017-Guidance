#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUMS 9999
pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;

int global_cnt = 0;

void *thread_worker(void *param)
{
    if ( 0 != pthread_mutex_trylock(&mylock) ) {
      printf("Unsuccessful attempt to acquire lock\n");
      // #######  pthread_mutex_unlock(&mylock); // Error: mutex not acquired!  ==> Only the thread that owns a mutex should unlock it! #########
      
    } else {
        global_cnt += 1;
        // printf("success\n");
        pthread_mutex_unlock(&mylock);
    }
    return NULL;
}

int main(void)
{
    pthread_t t[THREAD_NUMS];


    for (int i = 0; i < THREAD_NUMS; i++){
        pthread_create(&t[i], NULL, thread_worker, NULL);
    }

    for (int i = 0; i < THREAD_NUMS; i++){
        pthread_join(t[i], NULL);
    }

    printf("%d\n", global_cnt);
}