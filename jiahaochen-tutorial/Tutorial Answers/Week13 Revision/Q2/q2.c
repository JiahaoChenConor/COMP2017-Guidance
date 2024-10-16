#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
// #define MAX(x, y) x > y ? x : y

int main () {
    printf("%d\n", MAX(1, 2));

    printf("%d\n", MAX(10000, 4));

    printf("%d\n", 2 * MAX(3, 4)); // 8
        // 2 * 3 > 4 ? 3 : 4 => 6 > 4 ? 3 : 4 = 3
}


/*

    What are include guards?

    + avoid the problem of double inclusion when dealing with the include directive

*/