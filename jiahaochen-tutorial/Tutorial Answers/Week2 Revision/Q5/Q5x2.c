#include<stdio.h>
int main(){
    const char * ptr = "hello";
    const char array[] = "hello";
    const char array2[] = { 'h', 'e', 'l', 'l', 'o' };
    const char array3[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    const char array4[5] = { 'h', 'e', 'l', 'l', 'o' };
    const char array5[6] = { 'h', 'e', 'l', 'l', 'o', 0 };
    const char array6[20] = { 'h', 'e', 'l', 'l', 'o' };
    const char array7[20] = { 0 };
    const char array8[20] = "hello";

    //%zu is unsigned int
    printf("%zu %zu\n", sizeof(ptr), sizeof(array));
    // 8 6
    // pointer ptr in bit64 opertaing system is 8 bytes ； sizeof(array) represents the length of whole array

    printf("%zu %zu\n", sizeof(array2), sizeof(array3));
    // 5, 6

    printf("%zu %zu\n", sizeof(*ptr), sizeof(&array));
    printf("%zu\n", sizeof(ptr));
    // sizeof(*ptr) is the size of first element of *ptr which is 'h' 
    // ； &array is the whole address of array which is the address of first element of array（since 64bits operating system so 8bytes）
    // 1, 8

    printf("%zu %zu\n", sizeof(&array2), sizeof(&array3));
    // 8, 8

    return 0;
}




// For a 32 bit computer, the pointer size can be 4 bytes; 64bit computers can have 8 bytes