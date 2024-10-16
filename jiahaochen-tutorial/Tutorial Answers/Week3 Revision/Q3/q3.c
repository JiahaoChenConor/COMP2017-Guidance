#include <stdio.h>
#include <stddef.h>

int main(){


    /*
        t
            Specifies that a following d, i, o, u, x, or X conversion specifier 
            applies to a ptrdiff_t or 
            the corresponding unsigned integer type argument; 
            or that a following n conversion specifier applies to a pointer to a ptrdiff_t argument.
    */

    // td:  difference between the two pointers according to the data type
    // address difference / sizeof(type)


    // &x + offset * sizeeof(type(x))
    // address diff / sizeof(type(x))


    // %td for type ptrdiff_t  : the difference for pointers and Pointer arithmetic works like : address diff / sizeof(type)
    
    int x = 1;
    printf("%p %p\n", &x, &x + 1); // + 4 bytes: next integer

    char y = 'c';
    printf("%p %p\n", &y, &y + 1); // + 1 byte

    char z[100];
    printf("%p %p %td\n", &z[1], z + 5, &z[12] - &z[9]); // +1 byte   +4 bytes     3
    printf("%p %p\n", &z[3] - 1, &z[20] - 5); 

    double u[100];
    printf("%p %p %td\n", &u[1], u + 2, &u[12] - &u[9]); // +1*8 byte   +2*8    3 
    printf("%p %p\n", &u[3] - 1, &u[20] - 5);// +2*8    + 15*8

    printf("%c %d\n", 'a' + 1, 'z' - 'a'); // b 25

}

    
