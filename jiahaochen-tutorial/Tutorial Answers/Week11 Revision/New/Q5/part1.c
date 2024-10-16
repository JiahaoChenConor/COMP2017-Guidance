#include <stdio.h>
#include <pthread.h>
#define NTHREADS 2
#define REPEATS 10000000
// #define USEATOMIC
#ifndef USEATOMIC
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif

unsigned counter = 0;

void* worker(void* arg) {
    for (unsigned i = 0; i < REPEATS; i++) {
        // NOTE: this code is here to benchmark the synchronisation
        // mechanism you should not attempt to atomically increment
        // a highly contended global counter if you can avoid it.
        // A much faster way would be save the results of the sum
        // on the stack and then add it atomically to the final value.
        #ifdef USEATOMIC
            __sync_fetch_and_add(&counter, 1);
        #else

        pthread_mutex_lock(&mutex);
        counter += 1;
        pthread_mutex_unlock(&mutex);
        #endif
    }
    return NULL;
}
int main(void) {
    pthread_t thread_ids[NTHREADS];

    for (size_t i = 0; i < NTHREADS; i++) {
        pthread_create(thread_ids + i, NULL, worker, NULL);
    }
    for (size_t i = 0; i < NTHREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    printf("%u\n", counter);
    return 0;
}

/*
time ./a.out ==> without USEATOMIC
20000000

real0m0.956s
user0m1.402s
sys0m0.462s


time ./a.out ==> with USEATOMIC
20000000

real0m0.355s
user0m0.691s
sys0m0.000s


performance:

Atomic operations leverage processor support (compare and swap instructions) and don't use locks at all, 
whereas locks are more OS-dependent and perform differently on, for example, Win and Linux.

Locks actually suspend thread execution, freeing up cpu resources for other tasks, 
but incurring in obvious context-switching overhead when stopping/restarting the thread. 
On the contrary, threads attempting atomic operations don't wait and keep trying until success (so-called busy-waiting), 
so they don't incur in context-switching overhead, but neither free up cpu resources.

Summing up, in general atomic operations are faster if contention between threads is sufficiently low. 
You should definitely do benchmarking as there's no other reliable method of knowing what's the lowest overhead between context-switching and busy-waiting.
*/