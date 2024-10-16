#include<stdio.h>
#include<stdlib.h>
typedef int (*calli)(int, int);

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int exectue(int a, int b, int (*fn)(int, int)){
    return fn(a, b);
}


int main(){
    // int (*fn)(int, int) = add;
    calli fn = add; // or &add
    int pairs[4][2] = {
        {1, 2},
        {2, 6},
        {3, 3},
        {4, 10}
    };

    // // since [] has a higher priority than *, fns is an array whose element are pointers 
    // int (*fns[4])(int, int) = {
    //     add, 
    //     sub,
    //     sub,
    //     add
    // };

    calli fns[4] = {
        add, 
        sub, 
        sub,
        add
    };
    for (int i = 0; i < 4; i++){
        if ((i % 2) == 0){
            fn = add;
        }else{
            fn = sub;

        }

        exectue(pairs[i][0], pairs[i][1], fn);

    }


    return 0;
}
