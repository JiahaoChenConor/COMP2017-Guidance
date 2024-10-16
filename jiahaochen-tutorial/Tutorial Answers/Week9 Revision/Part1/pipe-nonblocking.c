// from the live lecture

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <errno.h>

int main() {

	int fd[2] = { -1, -1};
    // read, write
	printf("%d %d\n", fd[0], fd[1]);	

	int ret = pipe(fd);

	printf("%d %d\n", fd[0], fd[1]);	

    // write data into write end
	char *data = "zoo's are delicious";
    write (fd[1], data, strlen(data)+1);


	char buffer[6];
	ssize_t nread;
	
    fcntl(fd[0], F_SETFL, fcntl(fd[0], F_GETFL) | O_NONBLOCK);

	while (1) {
		//  `read` 5 bytes every time, check the return value (how many bytes have been read)
		nread = read(fd[0], buffer, 5);
        // why our program does not end ?  ==> read is blocking until some data write into pipe
		if (nread <= 0) {
            printf("%d\n", nread);
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // EAGAIN: there is no data available right now, try again later
                // EWOULDBLOCK: your thread would have to block in order to do that
				perror("Error");
			};
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


