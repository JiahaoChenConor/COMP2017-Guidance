#include <stdio.h>
#include <string.h>

int replace_words(FILE* fp_in, FILE* fp_out, const char* find, const char* replace){
    if (fp_in == NULL){
        return -1;
    }

    // arr to store info in original file
    char arr[1024];

    while (fgets(arr, 1023, fp_in) != NULL) {
        char buf[1024];
        memset(buf, 0, 1024);

        char *ptr_buf = buf;

        /*
            On a first call, the function expects a C string as argument for str, 
            whose first character is used as the starting location to scan for tokens. 
            In subsequent calls, the function expects a null pointer and 
            uses the position right after the end of last token as the new starting location for scanning.

            Once the terminating null character of str is found in a call to strtok, 
            all subsequent calls to this function (with a null pointer as the first argument) return a null pointer.
        
        */
        
        // split by space
        for (char *token = strtok(arr," "); token != NULL; token = strtok(NULL, " "))
        {   
            // compare with string needed be replaced 
            if (strcmp(token, find) == 0) { // token == find
                strncpy(ptr_buf, replace, strlen(replace));
                ptr_buf += strlen(replace);
            } else {
                strncpy(ptr_buf, token, strlen(token));
                ptr_buf += strlen(token);
            }

            // if not end and not the last token in the line. 
            if (token != NULL && !strstr(token, "\n")){
                ptr_buf[0] = ' ';
                ptr_buf++;
            }
        }

        fprintf(fp_out, "%s", buf);
    }

    

    return 0;
}

int main(int argc, char* argv[]) {
    FILE* read = fopen(argv[1], "r");
    FILE* write = fopen(argv[2], "w");

    if (read == NULL || write == NULL) {
        perror("unable to open file");
        return 1;
    }

    replace_words(read, write, argv[3], argv[4]);

    fclose(read);
    fclose(write);
}
