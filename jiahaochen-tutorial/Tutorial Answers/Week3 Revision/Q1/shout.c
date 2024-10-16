#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 101 // the last one for terminating 


int main() {

    char buf[BUF_SIZE]; 
    char *p = buf;  // *(p + 1) => buf[1]

    char temp = getchar(); // get the first char
    int len = 0;

    while (temp != '\0' && temp != '\n' && len < 100){
        if (temp >= 'a' && temp <= 'z'){
            temp = toupper(temp); // temp -= 'a' - 'A';
        }
        *p = temp; // buf[p] = temp
        p++; // p++;
        temp = getchar();
        len++;
    }

    *p = '\0';
    printf("%s\n", buf);
    // retrun 0;
}
