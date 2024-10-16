#include <stdio.h>
#include <pthread.h>
#define MAX_GENERATIONS 10

pthread_t thr[3];
pthread_barrier_t mybarrier;

void* tfunc (void* arg){
    int i ;
    for (i = 0; i < MAX_GENERATIONS; i++){
        // do someting
        pthread_barrier_wait(&mybarrier);
    }
    return NULL;
}

int main(){
    int i, j;
    pthread_barrier_init(&mybarrier, NULL, 3);

    for (i = 0; i < 3; i++){
        pthread_create(&thr[i], NULL, tfunc, (void *) &j);
    }

    for (i = 0; i < 3; i++){
        pthread_join(thr[i], NULL);
    }   

    pthread_barrier_destroy(&mybarrier);
    return 0;
}

