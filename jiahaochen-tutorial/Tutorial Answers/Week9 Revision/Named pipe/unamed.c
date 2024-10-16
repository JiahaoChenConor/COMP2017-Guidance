#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd[2] = {-1};
	int ret = pipe(fd);



	int pid = fork();
	if (0 == pid) {
                printf("\nThis is child\n");
                char buff[1024];
                read(fd[0], buff, 1024);
                printf("%s\n", buff);
                        // child
        
                char* mess = "hello from child";
                write(fd[1], mess, strlen(mess) + 1);


	} else {
                // parent
                printf("\nThis is parent\n");
                char* mess = "hello from parent";
                write(fd[1], mess, strlen(mess) + 1);

                sleep(3);

                char buff[1024];
                read(fd[0], buff, 1024);
                printf("%s\n", buff);
	}

	close(fd[0]);
	close(fd[1]);
	return 0;

}
