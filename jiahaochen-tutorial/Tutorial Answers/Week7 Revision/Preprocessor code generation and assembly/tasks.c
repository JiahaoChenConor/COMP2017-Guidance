#include<stdio.h>
#define PI (3.14)

int main(){
    #ifdef EBUG
    printf("Hello DEBUG");
    #endif

    double a = PI;
    printf("%f", a);
    printf("Start");
    return 0;

}
