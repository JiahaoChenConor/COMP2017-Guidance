#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define SOME_DATA (24)

// ./mmap_with_files data.txt
int main(int argc, char** argv) {
    if(argc != 2) {
        //Need two arguments
        return 1;
    }

    char* block = NULL;
    // O_RDONLY -> O_RDWR
    int fd = open(argv[1], O_RDWR);
    struct stat stat_b;

    fstat(fd, &stat_b);

	// MAP_PRIVATE -> MAP_SHARED
    block = mmap(NULL, stat_b.st_size, PROT_WRITE | PROT_READ,
            MAP_SHARED, fd, 0);

    if(block == MAP_FAILED) {
        perror("MAP Failed");
        close(fd);
        return 1;
    }


    char* new_text = "change something";
    memcpy(block, new_text, strlen(new_text));


    // remember to unmap.
    munmap(block, stat_b.st_size);
    close(fd);
}
