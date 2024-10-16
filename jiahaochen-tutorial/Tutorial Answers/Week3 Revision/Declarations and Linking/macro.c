#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int main(){
    int a = 1, b = 2;
    // if (a++ < b){
    //     printf("case1: a: %d, b: %d", a, b);
    // }else{
    //     printf("case2: a: %d, b: %d", a, b);
    // }
    int y = min(a++, b);
    printf("y: %d a: %d, b: %d", y, a, b);

}