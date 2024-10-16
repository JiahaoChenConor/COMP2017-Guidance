#include <stdio.h>
#include "dynamicArray.h"
/*

    gcc -fsanitize=address -Wall -Werror -std=gnu11 test.c dynamicArray.c 

*/
int main(){

    dyn_array* my_array = dyn_array_init();

    // Test add
    dyn_array_add(my_array, 0);
    dyn_array_add(my_array, 1);
    dyn_array_add(my_array, 2);
    dyn_array_add(my_array, 3);
    dyn_array_add(my_array, 4);
    dyn_array_add(my_array, 5);

    // Test get value
    printf("%d\n",dyn_array_get(my_array, 0));
    printf("%d\n",dyn_array_get(my_array, 1));
    printf("%d\n",dyn_array_get(my_array, 2));
    printf("%d\n",dyn_array_get(my_array, 3));
    printf("%d\n",dyn_array_get(my_array, 4));
    printf("%d\n",dyn_array_get(my_array, 5));

    printf("%d\n",dyn_array_get(my_array, 6));


    // Test delete
    dyn_array_delete(my_array, 3);
    printf("%d\n",dyn_array_get(my_array, 0));
    printf("%d\n",dyn_array_get(my_array, 1));
    printf("%d\n",dyn_array_get(my_array, 2));
    printf("%d\n",dyn_array_get(my_array, 3));
    printf("%d\n",dyn_array_get(my_array, 4));
    printf("%d\n",dyn_array_get(my_array, 5));

    dyn_array_free(my_array);
}

