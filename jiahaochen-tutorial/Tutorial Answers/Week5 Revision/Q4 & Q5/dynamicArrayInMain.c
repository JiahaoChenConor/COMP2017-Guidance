#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAP (4)

int main(int argc, char** argv) {
	if(argc > 1) {
		int n = strtol(argv[1], NULL, 10);
		int* array = malloc(DEFAULT_CAP * sizeof(int));
        int size = 0;
        int capacity = DEFAULT_CAP;


		for(int i = 0; i < n; i++) {
			
            if(size + 1 > capacity) {
                int* temp = realloc(array, capacity * 2 * sizeof(int));
	
				if(temp != NULL) {
					array = temp;
					capacity = capacity * 2;
				} else {
					fprintf(stderr, "Cannot reallocate array");
				}
            }
			size++;
			array[size-1] = i*i;
		}
		

		for(int i = 0; i < n; i++) {
			printf("%d ", array[i]);
		}

		

		free(array);
	}

	return 0;
}

