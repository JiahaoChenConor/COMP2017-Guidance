#include <stdio.h>
void swap(int* a_pointer, int* b_pointer) {
    int temp = *a_pointer;
    *a_pointer = *b_pointer;
    *b_pointer = temp;
}

int main(void) {
    int a = 2;
    int b = 3;
    swap(&a, &b); //Specify the variables to swap
    printf("%d %d\n", a, b); // should print 3 2
    return 0;
}
