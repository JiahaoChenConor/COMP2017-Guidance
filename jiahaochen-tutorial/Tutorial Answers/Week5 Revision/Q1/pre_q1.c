#include <stdio.h>
#include <stdlib.h>


// • What is the lifetime of var_a,var_c, var_d and var_e?
//     + var_a is global variable(in global/static), the lifetime is whole sources files, including .h and .c file
//     + var_c is static variable(in global/static), the lifetime is only this file, do not be free after stack frame
//     + var_d is local variable(in stack frame:main), the lifetime is only in main function
//     + var_e is also in stack (but malloc is in heap), the lifetime of var_e I think is in main function

// • What would happen if we did not free var_e?
    // + memory leak, since var_e only exist in main function, but after this, the memory malloc created will not be free

// • When and where might memory leaks occur in this code?
    // + var_f not free
    
int var_a; // In C, multiple global variables are "merged" into one

int sum (const int* var_b) {
    static int var_c;
    var_c += *var_b;
    return var_c;
}

int main (int argc, char** argv) {
    int var_d = 1;
    int* var_e = malloc(sizeof(int));
    if (NULL == var_e)
    {
        perror("Malloc Failed!");
            return 1;
    }
    var_a = 2;

    *var_e = 2;
    printf("%d\n", sum(&var_d));
    printf("%d\n", sum(&var_a));
    printf("%d\n", sum(var_e));
    sum(var_e);

    char* var_f = calloc(sizeof(char), 100);
    if (NULL == var_f)
    {
        perror("Calloc Failed");
        return 1;
    }

    free(var_e);

    return 0;
}
