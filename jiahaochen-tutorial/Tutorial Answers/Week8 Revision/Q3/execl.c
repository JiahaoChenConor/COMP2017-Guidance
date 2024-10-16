#include <stdio.h>
#include <unistd.h>
int main(void) {
    puts("about to launch sort");

    // path, arguments, null means end of argu
   
    if (execl("/usr/bin/echo", "echo", "hello", (char*) NULL) == -1) {
        perror("exec failed");
        return 1;
    }
    
    // 
    puts("end echo");

    return 0;
}