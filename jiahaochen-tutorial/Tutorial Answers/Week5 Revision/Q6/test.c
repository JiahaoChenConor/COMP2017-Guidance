#include <stdlib.h>
#include <stdio.h>

int main() {
	long *a = calloc(sizeof(long),8); //Buf of 72 bytes 8*8
	long *b = calloc(sizeof(long),9); //Buf of 72 bytes 8*9

	for(size_t i = 0; i < 8; i++){
		a[i] += i >> 1; //Fixes writing over the end of the buffer
		b[i] = -1; // Fixes overflow
	}

	// *((int*)0) = 1;

	int ret = (int)a[0];
	free(a);
	free(b);
	printf("%d\n", ret);
	return ret;
}
