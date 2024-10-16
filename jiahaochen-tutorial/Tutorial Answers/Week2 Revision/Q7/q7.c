#include<stdio.h>

void swap(int a[], int b[]) // int* a， pointer a is an address
{
    int temp = 0;
    temp = a[0];
    a[0] = b[0];
    b[0] = temp;

}
int main(void){
    int a = 2;
    int b = 3;

    swap(&a, &b);
    printf("%d, %d\n", a, b);

    return 0;
}
