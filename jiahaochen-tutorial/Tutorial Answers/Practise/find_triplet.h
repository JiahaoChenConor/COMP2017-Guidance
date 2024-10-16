#include<stdio.h>
#include<threads.h>
#include<pthread.h>
#include<stdint.h>
#include <stdlib.h>
typedef struct thread_data{
    int thread_id;
    int16_t *results; // staring indexs
    int results_size; // how many results
}TDATA;

extern int array_size;

extern int * array;

extern int number_of_threads;

extern int get_global();

extern void set_global(int val);

extern pthread_mutex_t global_lock;

extern void * find_triplet_thread_worker(void* args);
