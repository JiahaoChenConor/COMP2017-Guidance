#include<stdio.h>



/*
    argv |ptr1|ptr2|
*/


// argv is an array. Elements are pointers(address) to character
int main(int argc, char* argv[]){
    for (int i = 1; i < argc; i++){
        // %s expects a type of char*.
        printf("%s ", argv[i]); // print till \0
    }

    printf("\n");

    for (int i = 1; i < argc; i++){
        printf("%s ", *(argv + i));
    }


}
