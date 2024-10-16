#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_integers(void* ptr, size_t size){
    int* ptr_int = (int*)ptr;
    for (int i = 0; i < size; i++){
        printf("%d ", *(ptr_int + i));
    }
}

/*
 * Our comparator function for integers
 */
int int_cmp(void* a, void* b) {
	int* a_ptr = (int*) a;
	int* b_ptr = (int*) b;

	return (*a_ptr) - (*b_ptr);
}

int char_cmp(void* a, void* b){
	char* a_ptr = (char*) a;
	char* b_ptr = (char*) b;
	return (*a_ptr) - (*b_ptr);
}

/*
 * Bubble sort implementation, we use memcpy and a void* buffer for temporary storage
 * We then throw int_cmp (this would be passed in main) to the function to be executed
 */
void bubble_sort(void* elements, size_t n, size_t size_element, int (*cmp)(void*, void*)) {
	int keep_repeating = 1;
    // temp for swap
	void* buff = malloc(size_element);
	for(int i = 0; i < n; i++) {
	
		for(int j = 0; j < (n-1); j++) {
			// compare  elements[j] with elements[j + 1], if the previous is larger, swap
			if(cmp(elements+(j*size_element), elements+((j+1)*size_element)) > 0) {
                
                // swap value
				memcpy(buff, elements+(j*size_element), size_element);
				memcpy(elements+(j*size_element), elements+((j+1)*size_element), size_element);
				memcpy(elements+((j+1)*size_element), buff, size_element);


				
			}
			
		}
	}

    
	free(buff);
}

int main(){
    int array[5] = {3, 4, 5, 6, 1};
    bubble_sort((void*) array, 5, sizeof(int), int_cmp);
    print_integers(array, 5);


	char carray[5] = {'e', 'f', 'a', 'd', 'c'};
    bubble_sort((void*) carray, 5, sizeof(char), char_cmp);
    for (int i = 0; i < 5; i++){
		printf("%c ", carray[i]);
	}


}