#include <stdio.h>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MIN_W(a, b) a < b ? a : b
// danger if before MIN_W, there are some operations like * 

int main(){
    int a = 0;
    int c = MIN_W(a++, 2); // increase a twice (problem for two)
    // y = ((a++)<(b) ? (a++):(b)

    printf("a value: %d, c value: %d", a, c); // 2 , 1

}


