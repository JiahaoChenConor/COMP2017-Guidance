#include <stdio.h>
int main(){
    struct bs{
        unsigned m: 6;
        unsigned n: 12;
        unsigned p: 4;
    };
    printf("%zu\n", sizeof(struct bs));
    return 0;
}

1. check what changes in difference os systems 32 bits OS
 + sizeof(b) and sizeof(c) the size of the pointer 8 ==> 4
 + About the szie of integer

