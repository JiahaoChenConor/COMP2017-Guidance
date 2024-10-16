#include <stdio.h>
#include <pthread.h>

int data_avail = 0;
pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t data_cond = PTHREAD_COND_INITIALIZER;

void* producer(void *){
    // Produce data

    // Lock the whole queue
    pthread_mutex_lock(&data_mutex);
    /* Insert data into queue
        xxxxxx
    */

    // Set the data available into true
    data_avail = 1;
    // Send the signal to consumer, inform it there are some data available in queue
    pthread_cond_signal(&data_cond);
    
    // Unlock the whole queue
    pthread_mutex_unlock(&data_mutex);
    return NULL;
}

void *consumer(void *){

    pthread_mutex_lock(&data_mutex);

    // Use the while loop, so there can be more than one thread waiting 
    // And we can avoid Spurious wake
    while (data_avail == 0){
        pthread_cond_wait(&data_cond, &data_mutex);
        // When this function is executed, the mutex is unlocked and blocked until the signal appears
        // When this function return, lock the mutex again.
    }

    // woken up, execute critical section:

    /* 
        Extract data from queue;
    */

    if (/*queue is empty*/1){
        data_avail = 0;
    }

    pthread_mutex_unlock(&data_mutex);

    /*
        consume_data();
    */

    return NULL;
}


