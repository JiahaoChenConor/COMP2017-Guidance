#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LENGTH 100000000
#define NTHREADS 4
#define NREPEATS 10
#define CHUNK (LENGTH / NTHREADS)

/*
	False sharing
	
	In computer, we do not directly read data from the main memory RAM(slow)
	We move data into cache. Then read from cache

	cache store data line by line. Like read data from RAM by 8 bytes
	if `a` takes up 4 bytes. `b` takes up 4 bytes.
	When we read `a`. We will read `b` as well. The same when reading `b`

	memory 
	|a|b|

	Two threads

	core1: change `a`       	core2: read `b`
	|a|b|        				|a|b|

	
	+ what happens ?
		core1 change `a`. write back to memory and make this line invalid.
		Although `b` has no relation wit `a`. core2 need to read from memory again.
		Since the line has become invalid.
		The speed will be slower
*/

// https://zhuanlan.zhihu.com/p/65394173
typedef struct {
	size_t id;
	long* array;
	long result;
} worker_args;

void* worker(void* args) {

	worker_args* wargs = (worker_args*) args;

	// id is the n-th thread. 
	// start is (id * LENGTH)
	const size_t start = wargs->id * CHUNK;

	// end has two possibilities 1. Last one. the end is LENGTH  2.(id + 1) * LENGTH
	const size_t end = wargs->id == NTHREADS - 1 ? LENGTH : (wargs->id + 1) * CHUNK;



	// Solution
	// 1. padding
	// 2. local variable 

	// Use local stack variable to prevent false sharing
	long sum = 0;

	// Sum values from start to end
	for (size_t i = start; i < end; i++) {
		sum += wargs->array[i];
	}

	wargs->result = sum;
	return NULL;
}

int main(void) {

	long* numbers = malloc(sizeof(long) * LENGTH);
	for (size_t i = 0; i < LENGTH; i++) {
		numbers[i] = i + 1;
	}

	worker_args* args = malloc(sizeof(worker_args) * NTHREADS);
	for (size_t n = 1; n <= NREPEATS; n++) {
		for (size_t i = 0; i < NTHREADS; i++) {
			args[i] = (worker_args) {
				.id     = i,
				.array  = numbers,
				.result = 0,
			};
		}

		pthread_t thread_ids[NTHREADS];

		// Launch threads
		for (size_t i = 0; i < NTHREADS; i++) {
			pthread_create(thread_ids + i, NULL, worker, args + i);
		}

		// Wait for threads to finish
		for (size_t i = 0; i < NTHREADS; i++) {
			pthread_join(thread_ids[i], NULL);
		}

		long sum = 0;

		// Calculate total sum
		for (size_t i = 0; i < NTHREADS; i++) {
			sum += args[i].result;
		}

		printf("Run %2zu: total sum is %ld\n", n, sum);
	}

	free(args);
	free(numbers);
}
