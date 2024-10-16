// from the live lecture

#include <stdio.h>
#include <string.h>

#include <unistd.h>

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
	
	while (1) {
		//  `read` 5 bytes every time, check the return value (how many bytes have been read)
		nread = read(fd[0], buffer, 5);
        // why our program does not end ?  ==> read is blocking until some data write into pipe
		if (nread <= 0) {
			printf("%d\n", nread);
			perror("read issues");
			break;
		} else {
			buffer[5] = '\0';
			printf("nread: %zd\n", nread);
			printf("buffer: %s\n", buffer);
            //  // Way1: 
            // if (strcmp(buffer, "ious") == 0){
            //     break;
            // }

            // Way2: when read (the end of file), here it means when we close write end, return 0
            // comment close(); before return 0;
            // close(fd[1]);

            // // Way3: make non-blocking, it will return -1 and set errno to EWOULDBLOCK or EAGAIN

		}
	}
	
	close(fd[0]);
	// close(fd[1]);

	return 0;
}


