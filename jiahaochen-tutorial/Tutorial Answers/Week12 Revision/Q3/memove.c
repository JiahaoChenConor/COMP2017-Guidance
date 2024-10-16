#include <stdio.h>
#include <string.h>


void cpy2(char * dest, char * src, size_t n) {
for (size_t i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
}


int main(){

    char s[] = "123456";
    memmove(s + 1, s, 4);

    // cpy2(s+1, s, 4);
    printf("%s\n", s);
}
