#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

#define BUF_SIZE (80)


int main(){
    char buff[BUF_SIZE];
	char* n_check = NULL;

    int fd;

    // FIFO file path
    char * myfifo = "myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

	while(1) {
		printf("> ");
		n_check = fgets(buff, BUF_SIZE, stdin);
        // replace the '\n' with '\0'
        buff[strlen(buff) - 1] = '\0';
		
		if(n_check != NULL) {
			pid_t pid = fork();
			if(pid == 0) {

                fd = open(myfifo, O_WRONLY);
                write(fd, buff, 80);
                close(fd);

				return 0;
			}else{
				wait(NULL);
			}
		}
	}
}

