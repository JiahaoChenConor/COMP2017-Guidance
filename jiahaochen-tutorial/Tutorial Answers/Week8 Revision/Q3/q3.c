#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE (1024)
#define ARG_SIZE (512)
#define BIN_PATH "/usr/bin/"

int main() {

	char arg0[ARG_SIZE];  // for command
	char arg1[ARG_SIZE]; // for argument1
	char buf[BUF_SIZE];  // buffer
	char* n_check = NULL;

	while(1) {
		printf("> ");
		n_check = fgets(buf, BUF_SIZE, stdin);
        // get two strings from buffer
		sscanf(buf, "%s %s", arg0, arg1);
		
		
		if(strcmp(arg0, "exit") == 0) {
			break;
		}
		
		if(n_check != NULL) {
			pid_t pid = fork();
			if(pid == 0) {
                // copy the bin path eg. /usr/bin/cat
				snprintf(buf, BUF_SIZE, BIN_PATH"%s", arg0);
				// fprintf(stderr, "%s %s %s", buf, arg0, arg1);
            
                // command arg0 arg1
				// /usr/bin/cat cat file.txt
				execl(buf, arg0, arg1, (char*) NULL);
				return 0;
			}else{
				// by this, we can not & at background. ==>>>>>> Question! Why?
				// try to run 
				// since the parent process must wait child process
				wait(NULL);
			}
		}
	}
}


