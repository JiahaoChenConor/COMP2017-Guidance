#include<stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"


struct dyn_array* dyn_array_init(){
    dyn_array* my_array = malloc(sizeof(dyn_array));
    if (NULL == my_array){
        fprintf(stderr, "Not enough memory!");
        return NULL;
    }

    my_array -> size = 0;

    my_array -> array = malloc(sizeof(int) * DEFAULT_SIZE);
    if (NULL ==  my_array -> array){
        fprintf(stderr, "Not enough memory! for array");
        // if fail, free the previous
        free( my_array);
        return NULL;
    }

    my_array -> capacity = DEFAULT_SIZE;
    return  my_array;
}


void dyn_array_add(struct dyn_array* dyn, int value){
    if (NULL == dyn){
        return;
    }

    if (dyn->size + 1 > dyn->capacity){
        // realloc
        dyn->array = realloc(dyn->array, (dyn->capacity + DEFAULT_SIZE) * sizeof(int)); // do not forget * sizeof(int)
        // check ret value
        dyn->capacity += DEFAULT_SIZE;    
    }

    dyn->size++;
    (dyn->array)[dyn->size - 1] = value;
    
    return;

}
void dyn_array_delete(struct dyn_array* dyn, int index){
    if (NULL == dyn || index >= dyn->size){
        return;
    }

    /*
        size == 6

        |   1  |    2   |   3   |   4   |   5   |   6   |
            0       1       2    

        delete index 2

        copy 4 to 3, 5 to 4 ... till the end        
    
    */
    for (int i = index; i < dyn->size - 1; i++){
        *(dyn -> array + i) = *(dyn -> array + i + 1);
    }
    dyn->size --;
    
}
/*
    dyn_array_get
    Returns a pointer to the next node in the list
    :: struct dyn_array* dyn :: The dynamic array
    :: int index :: the index at the specific array
    Return the int at the specified index
*/
int dyn_array_get(struct dyn_array* dyn, int index){
    if (NULL == dyn || index >= dyn->size){
        fprintf(stderr, "Error in get, index out of range\n");
        return -1;
    }

    return *(dyn->array + index);

}
/*
    dyn_array_free
    Frees the current array allocation
    :: struct dyn_array* dyn :: The dynamic array
    Does not return anything
*/
void dyn_array_free(dyn_array* dyn){
    if (NULL == dyn){
        return;
    }

    if (NULL != dyn->array){
        // the order for freeing
        free(dyn->array);
        free(dyn);
    }
}


