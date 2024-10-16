// from the live lecture

#include <stdio.h>
#include <string.h>

#include <unistd.h>

int main() {

	int p2cfd[2] = { -1, -1};
	int c2pfd[2] = { -1, -1};

	int ret = pipe(p2cfd);
	ret = pipe(c2pfd);


	int pid = fork();
	if (pid != 0) {
		// parent process
		// sleep(10);
		// SEND quit
		char *command = "quit";
		write(p2cfd[1], command, 5);

		printf("parent sent command %s\n", command);

		// Expect OK
		char buffer[10];
		read(c2pfd[0], buffer, 3);

		printf("message returned is: %s\n", buffer);
	} else {

		// child process
		
		// Expect command
		char buffer[10];
		read(p2cfd[0], buffer, 5);

		char *command = buffer;
		// is the command valid?
		printf("received command: %s\n", command);

		// send back the OK
		write(c2pfd[1], "OK", 3);
		
		printf("child recieved and replied. terminating...\n");
	}

	close(p2cfd[0]);
	close(p2cfd[1]);
	close(c2pfd[0]);
	close(c2pfd[1]);


	return 0;
}


