#include <stdio.h>

int anint;
 
void foo(int *ptr)
{
    anint = 1;
    *ptr = 3; 
    printf("%d\n", anint);
    /*
        it looks safe to assume that `anint` is a constant 1.
        But `ptr` may change the anint
        so the old complier will insert code to reload the value of `anint` for the call
    
    */
}


int main(){
    int a = 0;
    foo(&a);
    
    foo(&anint);
}