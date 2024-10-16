#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#define SOME_DATA (24)

// ./mmap_with_files data.txt
int main(int argc, char** argv) {
    if(argc != 2) {
        //Need two arguments
        return 1;
    }

    char* block = NULL;
    int fd = open(argv[1], O_RDONLY);
    struct stat stat_b;
    // get the status of file, put it into structure stat
    fstat(fd, &stat_b);

	/*
		It is used to map the content of a file to the memory,
		and the access to the memory area is to read and write the content of the file directly.
		
		void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offsize);
		@param start: the corresponding memory address, NULL -> let the system decide


        + MAP_SHARED VS MAP_PRIVATE
            MAP_PRIVATE: can not write to file directly (create a copy when writing, we edit the copy)
            MAP_SHARED: write back to file. Shared with other process


	*/
    block = mmap(NULL, stat_b.st_size, PROT_WRITE|PROT_READ,
            MAP_PRIVATE, fd, 0);

    if(block == MAP_FAILED) {
        perror("MMAP Failed");
        close(fd);
        return 1;
    }


    //Read from the file
    for(size_t i = 0; i < SOME_DATA; i++) {
        printf("%c", block[i]);
    }

    printf("\n");

    // remember to unmap.
    munmap(block, stat_b.st_size);
    close(fd);
}
