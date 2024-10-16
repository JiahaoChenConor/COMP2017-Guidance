#include<stdio.h>

/*
    -------------------------
    |   n=1                 |
    |  return 1             |   at this stage all the previous stack frame are needed
    -------------------------
    |   n=2                 |
    |  return 1 * f(1)      |
    -------------------------
    |   n=3                 |
    |  return 3 * f(2)      |
    -------------------------
*/
int factorial(int n){

    if (n == 1){
        return 1;
    }

    return n * factorial(n - 1);
}



/*

    -------------------------
    |   n=1                 |
    |  return  3*2*1        |   at this stage all the previous stack frame are no needed
    -------------------------
    |   n=2                 |
    |  return f(1, 3*2)     |
    -------------------------
    |   n=3                 |
    |  return f(2, 1*3)     |
    -------------------------
*/


int factorial_tail_call(int n, int res){
    if (n == 1){
        return res;
    }

    return factorial_tail_call(n-1, res * n);
}


