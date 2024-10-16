#include <stdlib.h>
#include <stdio.h>

int main() {
	void *a = malloc(sizeof(int*)*(1 << 3)); // 8 * binary 1000 = 8 * 8 = 64

	void *b = malloc(sizeof(int*)*9); // 8 * 9 = 72

    // size_t is (long unsigned int)
    // to ensure every block can store type size_t, we cast pointer into long type
    // 9 ==> 8 to ensure not write the memory out of bound

    //  size_t be at most as big as an unsigned long. 
	for(size_t i = 0; i < 8; i++) {
		((long*)a)[i] = i >> 1;
		((long*)b)[i] = i + ~i; // 0 + ~0 = ~0 is max for long unsigned int which will cause overflow if b is int
	}

    //  record before free
    int ret = (int) ((long*)a) [0];

	free(a);
    // the original forget free b as well.
    free(b);

    // printf("%d\n", (int) (((long*)a)[0]));
	return ret;
}
