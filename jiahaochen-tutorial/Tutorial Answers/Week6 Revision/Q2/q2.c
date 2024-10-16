#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void printBytes();


int main(){
    // 0 stdin, 1 stdout, 2 stderr
    int fd = open("example.out", O_WRONLY);
    printf("%d\n", fd);
    // 3

    close(STDIN_FILENO); //  1 is empty
    dup(fd);
    /* 
        The dup() (short for duplicate) system call makes a copy of a 
        file descriptor into the lowest available index in the table.
    */

    // so the file description 1 will become fd
    // and we write to the file
    char line[] = "Hello World";
    write(STDIN_FILENO, line, sizeof(line));

    // check the file
    printBytes();
}


void printBytes(){
    unsigned char buffer[11];
    FILE *ptr;

    ptr = fopen("example.out","rb");  // r for read, b for binary

    int res = fread(buffer,sizeof(buffer), 1, ptr); // read 11 bytes to our buffer

    fclose(ptr);

    for (int i = 0; i < 11; i++){
        printf("%c", buffer[i]);
    }
}
