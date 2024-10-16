#include <stdio.h>

void myMemcpy(void* dest, const void* src, size_t len) {
    char *temp = dest;
    const char *s = src;

    while (len--){
        *temp++ = *s++;
    }
}

int main(){
    char s[10] = "abcd";
    char dest[10];

    myMemcpy(dest, s, 5);
    printf("%s\n", dest);
}
