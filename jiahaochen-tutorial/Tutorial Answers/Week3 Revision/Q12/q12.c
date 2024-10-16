#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define LEN (99)

void printFiles(int argc, char** argv){
    char buffer[LEN];
    FILE* fp = NULL;
    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-") == 0){
            continue;
        }


        fp = fopen(argv[i], "r");
        if (fp == NULL){
            perror("open file failed");
            continue;
        }

        while (fgets(buffer, LEN, fp) != NULL){
            printf("%s", buffer);
            memset(buffer,0,99);
        }

     
        fclose(fp);
    }   
    
}

void printStdin(){
    char buffer[LEN];

    memset(buffer,0,99);


    // make it non-blocking
    // fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);

    // int numRead = read(0, buffer, 99);
    fread(buffer, 1, 99, stdin);
    printf("%s", buffer);

}

int main(int argc, char* argv[]){
    // case1: only files
    if (argc > 1 && strcmp(argv[1], "-") != 0){
        printFiles(argc, argv);
    }
    // case2: only stdin
    else if (argc == 1){
        printStdin();
    }
    // case3: stdin + files "-"
    else if (argc > 1 && strcmp(argv[1], "-") == 0){
        printStdin();
        printFiles(argc, argv);
    }


    // There is a bug, when only ./a.out => we don't know the stdin from other
    // make it non-blocking
}