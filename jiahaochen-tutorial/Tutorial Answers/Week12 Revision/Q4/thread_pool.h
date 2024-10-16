#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

struct thread_job{
    void* (*fp) (void*); // The function poniter to be called
    void* args;                        // Arguments for the function    
    struct thread_job * next;         // next data;
};

struct thread_pool{
    size_t shutdown;        // is tpool shutdown or not, 1 ---> yes; 0 ---> no
    size_t max_threads;
    pthread_t* threads_id;   // An array of threads' id
    struct thread_job* queue_head; // queue of data to deal with
    pthread_cond_t  queue_avilable; // conditional variable
    pthread_mutex_t queue_lock;
};

typedef struct thread_job thread_job;
typedef struct thread_pool thread_pool;


struct thread_pool* thread_pool_new(size_t n);

struct thread_job* thread_job_new(void(*fn)(void*), void* data);

void thread_job_destroy(struct thread_job* j);

void* thread_pool_work(void* arg);

void thread_pool_execute(struct thread_pool* pool, struct thread_job* job);

void thread_pool_destroy(struct thread_pool* pool);
