#include<stdio.h>
#include <ctype.h>

int atoi(const char s[]) {
    /*
        -0123

        3 * 1 + 2 * 10 + 1 * 100 + 0  * 1000 * [-1]
    */
    int len = 0;


    // count len, not include '\0'
    for (int i = 0; s[i] != '\0'; i++){
        len++;
    }
    
    if (len == 0){
        fprintf(stderr, "%s", "Empty string\n");
        return 0;
    }

    int sum = 0;
    int count = 1;
    int j;
    // from the end
    for (j = len - 1 ; j != 0; j--){
        sum += (s[j] - '0') * count; // '1' - '0' = 49 - 48 => int
        count = count * 10;
    }

    // until the last char, we need to check whether it is a negative or not
    if (isdigit(s[0])){
        sum += (s[j] - '0') * count;
    }else{
        sum = 0-sum;
    }

    return sum;
}


int main(void) {
    printf("%d\n", atoi(""));
    printf("%d\n", atoi("0"));
    printf("%d\n", atoi("0123"));
    printf("%d\n", atoi("1234"));
    printf("%d\n", atoi("-1234"));
    return 0;

}
