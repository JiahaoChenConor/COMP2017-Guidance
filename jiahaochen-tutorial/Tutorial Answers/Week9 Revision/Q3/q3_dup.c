#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	
	if(pid == 0) {
		close(1);
		close(fd[0]);
		// 1. fd 1 become pipefd[1]
		dup(fd[1]); 
		// 2. child process is replcaced by "ls"
		execlp("/bin/ls", "ls", "-l", "./", NULL); //file descriptors are maintained
		// 3. Normally, this will go to stdout, but here, since fd 1 has replcaced by pipefd[1] write
		// anything list on the terminal will be enqueued into pipe
	} else if(pid > 0) {
		
		FILE* f = fdopen(fd[0], "r");
		char buf[1024];
		int i = 1;
		// 4. so parent process can print them through pipe read
		while((fgets(buf, 1024, f)) != NULL) {
			printf("Line %d: %s", i, buf);
			i += 1;
		}
	}
	
	return 0;
}
