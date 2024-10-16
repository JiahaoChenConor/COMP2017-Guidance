#include<stdio.h>

int main(){
    // int** a = ...  *a -> int*
    // int* a = ...  *a -> int
    int* p = {1, 2, 3};

    printf("%d", *p);
    return 0;

    /*
       1.  *p = p[0]   // deferenceing the pointer to the first element
       2.  *(p + 10) = p[10] // p + 10, the pointer points to the element with index 10, deferecing => the value of element with index 10
       3.  &r[20] = r + 20 // get address of the element with index 20  => a pointer to the first element + 20 
       4.  &(g[0]) = g // get address of the first element => pointer to the first element
       5.  &*p = &p[0] = p // deferenc and get address 
       6.  p++ = &p[1] // p++ => the pointer to the second element => get address of the second element
       7. &((r[5])[5])  = &((*(r + 5))[5]) = &(*(*(r + 5) + 5)) = (*(r + 5) + 5)
    */
}

