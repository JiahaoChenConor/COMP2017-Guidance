#include <stdio.h>

int main(){

    int a = 123456;
    int* ptr_a = &a;
    unsigned char* byte_ptr = (unsigned char*)ptr_a;
    printf("%x, %x, %x , %x", *byte_ptr, *(byte_ptr + 1), *(byte_ptr + 2), *(byte_ptr + 3));
}

// >> 40, e2, 1 , 0
  // 123456 = 1 E2 40   // little end  ian /big endian