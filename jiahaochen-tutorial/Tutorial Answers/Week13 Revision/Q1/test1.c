#include <stdio.h>

void f() {
    struct int_array {
        int* data;  //8 bytes
        int len;  // 4 bytes + 4 bytes
    };

    struct int_array arr;
    struct int_array* arr_ptr = &arr; 
    struct int_array arrs[100];
    printf("%p %p\n", &(arrs[50].len), &(arrs[50].data));
}


int main(){
   f();
}