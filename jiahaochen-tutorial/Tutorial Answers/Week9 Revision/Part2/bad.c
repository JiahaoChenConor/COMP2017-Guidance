#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*

    What happens to this? Can parent can child read successfully ?
*/
int main() {
	int fd[2] = {-1};
	int ret = pipe(fd);

	int pid = fork();
	if (0 == pid) {
                // child
                char buff[1024];
                read(fd[0], buff, 1024); 

                printf("child read from pipe: %s\n", buff);
        
                char* mess = "hello from child"; 
                write(fd[1], mess, strlen(mess) + 1);


	} else {
                // parent
                char* mess = "hello from parent";
                write(fd[1], mess, strlen(mess) + 1); 

                // sleep(3);

                char buff[1024];
                read(fd[0], buff, 1024);
                printf("parent read from pipe: %s\n", buff);
	}

	close(fd[0]);
	close(fd[1]);
	return 0;

}

