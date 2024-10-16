#include <stdio.h>
#include <stdlib.h>
#define NEXT_CHAR_BUFFER_SIZE (4)

char* getln() {
    size_t wSize = NEXT_CHAR_BUFFER_SIZE, index = 0;
    char* ln = malloc(NEXT_CHAR_BUFFER_SIZE);
    char ch = 0;

    while(ch != '\n') {
        ch = getc(stdin);
        /* Increment memory reallocation by buffer size */
        ln = index >= wSize ? realloc(ln, wSize += NEXT_CHAR_BUFFER_SIZE) : ln;
        ln[index++] = ch; /* *(ln + index++) = ch; */
    }
    ln[index] = '\0';
    return ln;
}

int main() {
    printf("Enter a word: ");
    char* ln = getln();
    free(ln);
    return 0;
}