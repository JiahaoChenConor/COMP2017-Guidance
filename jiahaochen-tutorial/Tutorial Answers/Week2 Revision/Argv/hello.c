#include<stdio.h>

int main(int argc, char** argv){
    //derference removes nesting
    printf("%s", argv[1]);
    printf("%s", *(argv + 1));
}
