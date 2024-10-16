#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

/*
    The buffer is a memory area, which is used between the input and output devices and the CPU to cache data.
    It enables low-speed input and output devices and high-speed CPU to work in coordination, 
    avoiding low-speed input and output devices from occupying the CPU, freeing up the CPU, and enabling it to work efficiently.

    The following conditions will cause the buffer to be flushed:
 　　 1. When the buffer is full;
 　　 2. Execute flush statement;
 　　 3. Execute endl statement;
 　　 4. Close the file.
*/

int main(){
    FILE *f = fopen("file.txt", "w+");

    fprintf(f, "%c\n", 'a');
    // test by your own computer, not ed.
    // with flush, it will write into the file immediately
    fflush(f);

    sleep(10);

    // close the file will flush cache
    fclose(f);
}
