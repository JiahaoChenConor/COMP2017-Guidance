#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
#define MAX_LEN 10000000
#define BOTH_WORK_LEN 100000

/*      
        a b c d b a => ptr to "a", len = 6
          b c d b   => ptr to "b", len = 4
            c d     => ptr to "c", len = 2, whoops => c != d return false

*/
bool is_palindrome(char * s, size_t len) {
    // terminating condition
    if (len <= 1) {
        return true;
        // check the first and last
    } else if (s[0] != s[len - 1]) {
        return false;
    }

    // cut the first and last
    return is_palindrome(s + 1, len - 2);
}

bool is_pa_iterative(char* s, size_t len){
    // // noon, len 4
    // // i < 2. index = 0 --> 4 - 0 - 1, 1
    // for (int i = 0; i < len / 2; i++){
    //     if (*(s + i) != *(s + len - i - 1)){
    //         return false;
    //     }
    // }

    while (len > 1){
        if (s[0] != s[len - 1]){
            return false;
        }
        s += 1;
        len -= 2;
    }

    return true;
}

int main(){
    /*
        Q1
    */
    // some test
//   printf("Should be true: %d\n", is_palindrome("madam", 5));
//     printf("Should be false: %d\n", is_palindrome("madamm", 6));

    printf("Should be true: %d\n", is_pa_iterative("noon", 4));
    printf("Should be true: %d\n", is_pa_iterative("racecar", 7));





    // /*
    //     Q2
    // */
   
    // char* str = malloc(MAX_LEN);
    // for (int i = 0; i < MAX_LEN; i++){ *(str + i) = 'a';}


    //  /* 
    //     segment fault.
    //     Do not use char str[MAX_LEN] here. BOTH seg
    //     why ?
    //     since it will be stored in the stack as well

    //     too many stack frame
    //  */
    // is_palindrome(str, MAX_LEN);
    // free(str);


    /*
        Q3
    */
    // printf("Should be true: %d\n", is_pa_iterative("madam", 5));
    // printf("Should be false: %d\n", is_pa_iterative("madamm", 6));

    // printf("Should be true: %d\n", is_pa_iterative("noon", 4));
    // printf("Should be true: %d\n", is_pa_iterative("racecar", 7));

    // is_pa_iterative(str, MAX_LEN);
    // free(str);


    
    // for (int i = 0; i < 1000; i++){
    //     char* str2 = malloc(BOTH_WORK_LEN);
    //     for (int i = 0; i < BOTH_WORK_LEN; i++){ *(str2 + i) = 'a';}

    //     is_pa_iterative(str2, BOTH_WORK_LEN); 
    //     // is_palindrome(str2, BOTH_WORK_LEN); 

    //     free(str2);
    // }
  
    // return 1;
}
