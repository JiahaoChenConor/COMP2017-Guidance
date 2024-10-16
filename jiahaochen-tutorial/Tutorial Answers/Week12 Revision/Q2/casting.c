#include <stdio.h>

int main(){
    int x = (int) 3.9; // will be truncated to 3
    float y = 2.3 + x; // some casts are implicit and happen automatically
     printf("%d %u\n", -1, (unsigned) -1);
    return 0;
}

