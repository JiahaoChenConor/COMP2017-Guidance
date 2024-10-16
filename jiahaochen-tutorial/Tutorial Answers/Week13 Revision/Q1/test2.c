#include<stdio.h>
#include <stdlib.h>
#include <stddef.h>

void* g(int x) { 
    union merged {
        int x;
        float y; 
    };

    static int counter = 0; 
    ++counter;

    union merged* ptr = malloc(sizeof(union merged)); 
    if (!ptr) {
        return NULL; 
    }

    ptr->x = x;
    return ptr; 
}


int main(){
    g(1);
}