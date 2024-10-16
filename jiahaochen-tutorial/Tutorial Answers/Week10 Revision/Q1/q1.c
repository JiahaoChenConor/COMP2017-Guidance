#include <stdio.h>
#include <pthread.h>

#define NTHREADS 4

void* worker(void* arg) {

	const int argument = *((int*) arg);
	printf("Hello from thread %d\n", argument);

	return NULL;
}

int main(void) {

	int args[NTHREADS] = { 1, 2, 3, 4 };
	pthread_t thread_ids[NTHREADS];

	// Create threads with given worker function and argument
	for (size_t i = 0; i < NTHREADS; i++) {
		if (pthread_create(thread_ids + i, NULL, worker, args + i) != 0) {
			perror("unable to create thread");
			return 1;
		}
	}

	// Wait for all threads to finish
	for (size_t i = 0; i < NTHREADS; i++) {
		if (pthread_join(thread_ids[i], NULL) != 0) {
			perror("unable to join thread");
			return 1;
		}
	}
}

//
// Part 1
//

// The kernel scheduler determines when the processes and threads get their share of CPU time.
// There is no guarantee that the threads will receive CPU time in the order they have been created.


//
// Part 2
//

// Threads share the same memory space, however forked processes do not.

// A thread can modify a variable and other threads and see this change.
// Forked processes on the other hand cannot see these changes.

