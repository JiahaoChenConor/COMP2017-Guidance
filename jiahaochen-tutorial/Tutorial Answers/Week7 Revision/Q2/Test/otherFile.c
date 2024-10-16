#include <stdio.h>

extern int x;
extern int add(int a, int b);
// extern int main(void);


int main(){
    printf("%d\n", add(x, 1));   
}
