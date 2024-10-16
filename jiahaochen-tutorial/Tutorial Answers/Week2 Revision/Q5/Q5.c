#include <stdio.h>

int main(){
    char* ptr = "cdef";
    char array[] = "abcd";

    /*
        char a[] = "abcd"           char* p = "cdef"
        
        a is an array               p is a pointer  

        sizeof(a) = 5             sizeof(p) = 8 / 4

        "abcd" in stack             p is in stack, "cdef" in code section (can not modify)

        &a same with a              p not same with &p

        a = "hello" invalid         p = "hello" valid
        since a is address          
        we can not change address

        a[0] = 'c'  valid           p[0] = 'c' invalid => segmentation fault
        array stored in stack        code section read only
        during the runtime, writeable                           


        // heap only exist at runtime
    
    
    */

        
    printf("%zu\n", sizeof(array));
    printf("%zu\n", sizeof(ptr));

    printf("%p\n", array);
    printf("%p\n", &array);

    printf("%p\n", ptr);
    printf("%p\n", &ptr);

    ptr = "hello";
    // array = "hello";

    // ptr[1] = 'm';
    array[1] = 'm';
    
}
