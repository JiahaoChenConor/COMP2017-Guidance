#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



void do_wc(FILE* f, const char* name) {

    int words = 0;
    int lines = 0;
    int bytes = 0;
    char c = 0;

    
    if(f != NULL) {
        
        int word_exists = 0;   // meets '\n' or ' ' does not means there is a word before '\n' or ' '
        // until the end of file
        while((c = fgetc(f)) != EOF) {
            printf("%c", c);
            // the end of line
            if(c == '\n') {
                lines++;
                // 3. when meets \n there may be a word before
                if(word_exists) {
                    words++;
                    word_exists = 0;
                }
            } else if(c == ' ') {
                // 2. when meets ' ', there may be a word before 
                if(word_exists) {
                    words++;
                    word_exists = 0;
                }
            } else {
                // 1. if meet a char instead of '\n', ' ', word exists
                word_exists = 1;
            }

            // for every char, bytes ++
            bytes++;
        }

        printf("%d\t%d\t%d\t%s\n", lines, words, bytes, name);
    }
}

int main(int argc, char** argv) {
    // printf all files
    if (argc > 1) {
        for(int i = 1; i < argc; i++) {
            // files
            FILE* f = fopen(argv[i], "r");
            if(f != NULL) {
                do_wc(f, argv[i]);
            }
            fclose(f);
        }
    } else {
        // echo hello | ./wc  ==> stdout to stdin (pipe)
        if(stdin != NULL) {
            do_wc(stdin, "stdin");
        }
    }
}
