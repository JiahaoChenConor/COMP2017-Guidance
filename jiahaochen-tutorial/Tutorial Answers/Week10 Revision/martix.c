#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#define WIDTH 512
#define IDX(x, y) ((y) * WIDTH + (x))

#define NTHREADS 4
#define CHUNK (WIDTH / NTHREADS)

typedef struct {
	size_t id;
	int* result;
	const int* a;
	const int* b;
} worker_args;

void* worker_multiply(void* args) {

	/*
    
        Line 1 2 3 4 5 6 7 8 9 10
    index    0 1 2 3 4 5 6 7 8 9

        4 Threads ==> CHUNK = WIDTH(9) / 4 = 2

        thread0: start = 0 * CHUNK = 0 * 2       end = (0+1) * CHUNK = 2     [0, 2)
        thread1: start = 1 * CHUNK = 2           end = 4                     [2, 4)
        thread2: start = 4                       end = 6                     [4, 6)
        thread3: start = 6                       end = WIDTH                 [6, 9)
    
    */
	worker_args* wargs = (worker_args*) args;

	const size_t start = wargs->id * CHUNK;
	const size_t end = wargs->id == NTHREADS - 1 ? WIDTH : (wargs->id + 1) * CHUNK;

	for (size_t y = start; y < end; y++) {
		for (size_t x = 0; x < WIDTH; x++) {
			for (size_t k = 0; k < WIDTH; k++) {
				 wargs->result[IDX(x, y)] += wargs->a[IDX(k, y)] * wargs->b[IDX(x, k)];
			}
		}
	}


	// // in the order of y, x, k => we can improve performance by uesing local variable
	// for (size_t y = start; y < end; y++) {
	// 	for (size_t x = 0; x < WIDTH; x++) {
	// 		float res = 0;
	// 		for (size_t k = 0; k < WIDTH; k++) {
	// 			 res += wargs->a[IDX(k, y)] * wargs->b[IDX(x, k)];
	// 		}
	// 		wargs->result[IDX(x, y)] = res;
	// 	}
	// }

	

	// // in the order of y, k, x => improve by cache
	// for (size_t y = start; y < end; y++) {
	// 	 for (size_t k = 0; k < WIDTH; k++){
	// 		 for (size_t x = 0; x < WIDTH; x++){				 
	// 			wargs->result[IDX(x, y)] += wargs->a[IDX(k, y)] * wargs->b[IDX(x, k)];
	// 		}
	// 	}
	// }

 

	return NULL;
}

/**
* Returns the matrix multiplication of a and b.
*/

int* naive_multiply(const int* a, const int* b) {
    int* result = calloc(WIDTH * WIDTH, sizeof(int));
    for (size_t y = 0; y < WIDTH; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            for (size_t k = 0; k < WIDTH; k++) {
                result[IDX(x, y)] += a[IDX(k, y)] * b[IDX(x, k)];
            }
        }
    }
    return result;
}
/**
* Returns the matrix multiplication of a and b.
*/
int* multiply(const int* a, const int* b) {

	int* result = calloc(WIDTH * WIDTH, sizeof(int));

	worker_args args[NTHREADS];
	pthread_t thread_ids[NTHREADS];

	for (size_t i = 0; i < NTHREADS; i++) {
		args[i] = (worker_args) {
			.a = a,
			.b = b,
			.id = i,
			.result = result,
		};
	}

	// Launch threads
	for (size_t i = 0; i < NTHREADS; i++) {
		pthread_create(thread_ids + i, NULL, worker_multiply, args + i);
	}

	// Wait for threads to finish
	for (size_t i = 0; i < NTHREADS; i++) {
		pthread_join(thread_ids[i], NULL);
	}

	return result;
}


int* generate_random_matrix(void) {
    // Ensure the width is a power of 2
    assert(((WIDTH - 1) & WIDTH) == 0);
    int* result = malloc(WIDTH * WIDTH * sizeof(int));
    for (size_t y = 0; y < WIDTH; ++y)
    {
        for (size_t x = 0; x < WIDTH; ++x)
        {
            result[IDX(x, y)] = rand();
        }
    }
    return result;
}
// Displays a matrix.
void display(const int* matrix) {
    for (size_t y = 0; y < WIDTH; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            printf("%4d ", matrix[IDX(x, y)]);
        }
        printf("\n");
    }
}
int main(void) {
    // Construct the matrices
    int* a = generate_random_matrix();
    int* b = generate_random_matrix();
    // Compute the result
    int* r = multiply(a, b);
    int* naive = naive_multiply(a, b);

    for (size_t y = 0; y < WIDTH; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            assert(naive[IDX(x, y)] == r[IDX(x, y)]);
        }
    }
    puts("done");
    free(a);
    free(b);
    free(r);
    return 0;
}
