#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {

	// pipefd[0] is read pipe, and pipefd[1] is write
	int pipefd[2];
	if (pipe(pipefd) < 0) {
		perror("unable to create pipe");
	}

	pid_t pid = fork();
	if (pid < 0) {
		perror("unable to fork");
	}

	if (pid == 0) {
		// close the write
		close(pipefd[1]);
		char buffer[20];
		read(pipefd[0], buffer, 9);
		if (strcmp(buffer, "bobafett") == 0) {
			printf("I will use the password \"%s\"\n", buffer);
		} else {
			puts("Aww no password");
		}
		// close all
		close(pipefd[0]);
	} else {
	    printf("The password is \"bobafett\"\n");
		// close the read
		close(pipefd[0]);
		write(pipefd[1], "bobafett", 9);
		wait(NULL);
		close(pipefd[1]);
	}

	return 0;
}

