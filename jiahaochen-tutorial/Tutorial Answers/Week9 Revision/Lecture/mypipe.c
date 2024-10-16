// from the live lecture

#include <stdio.h>
#include <string.h>

#include <unistd.h>

int main() {

	int fd[2] = { -1, -1};

	printf("%d %d\n", fd[0], fd[1]);	

	int ret = pipe(fd);

	printf("%d %d\n", fd[0], fd[1]);	

	char *data = "zoo's are delicious";
       	write (fd[1], data, strlen(data)+1);

	char buffer[6];
	ssize_t nread = read(fd[0], buffer, 5);

	if (nread <= 0) {
		perror("read issues");
	} else {
		buffer[5] = '\0';
		printf("nread: %zd\n", nread);
		printf("buffer: %s\n", buffer);
	}
	
	while (1) {
		//  `read` 5 bytes every time
		nread = read(fd[0], buffer, 5);
		if (nread <= 0) {
			perror("read issues");
			break;
		} else {
			buffer[5] = '\0';
			printf("nread: %zd\n", nread);
			printf("buffer: %s\n", buffer);
		}
	}
	
	close(fd[0]);
	close(fd[1]);

	return 0;
}

