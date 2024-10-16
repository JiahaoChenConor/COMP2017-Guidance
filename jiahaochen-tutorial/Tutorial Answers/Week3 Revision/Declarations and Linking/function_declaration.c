#include<stdio.h>

void print_out_data(int a); 

int main(){
    print_out_data(1);
    return 0;
}

void print_out_data(int a){ //2
    printf("%d\n", a);
    puts("a");
}

// we can compile if no 2
// no 1 ==> implicit declaration

// what is linking ?

// libc is loaded at runtime containing definitions of functions.



