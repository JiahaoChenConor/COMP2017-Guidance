#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#define DATA_SIZE (6)



// malloc some place and store data
int* give_data() {
    int* data = malloc(sizeof(int)*DATA_SIZE);
        for(int i = 0; i < DATA_SIZE; i++) { data[i] = i; }
        return data;
}

void read_share(int* d) {
    for(int i = 0; i < DATA_SIZE; i++) { printf("%d\n", d[i]); }
}

int main() {
    int* d = give_data();
    /*
        MAP_ANON:
        An anonymous mapping is established, 
        the parameter fd will be ignored at this time, and no files are involved
    */
    int* shared = mmap(NULL, DATA_SIZE*sizeof(int), PROT_READ|PROT_WRITE,
        MAP_ANON|MAP_SHARED, -1, 0);

    // change MAP_SHARED => MAP_PRIVATE

    // copy the data in heap into shared memory
    memcpy(shared, d, DATA_SIZE*sizeof(int));
    free(d);
    pid_t p = fork();
    if(p == 0) {
        printf("Child\n");
        // 1. child print 0 - 5
        read_share(shared);
        // 2. child add 10
        for(int i = 0; i < DATA_SIZE; i++) { shared[i] = i + 10; }
        munmap(shared, DATA_SIZE*sizeof(int));
    } else if(p > 0) {
        sleep(2);
        printf("Parent\n");
        // 3. Parent print 10 - 15 
        read_share(shared);
        munmap(shared, DATA_SIZE*sizeof(int));
    }
    return 0;
}
