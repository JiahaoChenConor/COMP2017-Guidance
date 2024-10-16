#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("word.txt", O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);
    printf("fd is: %d\n", fd);

    char buffer[10] = "abcd";

    write(fd, buffer, 5);

    // // test unbuffer
    // sleep(10);
    close(fd);

}
