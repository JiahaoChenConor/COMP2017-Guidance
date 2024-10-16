#include<stdio.h>
/*
    Static defined local variables do not lose their value between function calls. In other words they are global variables, but scoped to the local function they are defined in.

    Static global variables are not visible outside of the C file they are defined in.

    Static functions are not visible outside of the C file they are defined in.
*/
int f() {
    /*
        Static local variables are initialized at compile time, 
        so it is only initialized once, and have a initial value ​​when the program is running. 
        In the future, the initial value will not be reassigned every time the function is called, 
        but the value at the end of the last function call will be retained
    */
    static int i = 0;
    i++;
    printf("%d\n", i);
}

int main(){
    f();
    f();
    f();

    return 0;
}
