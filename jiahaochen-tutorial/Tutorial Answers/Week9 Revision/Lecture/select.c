#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>

int main() {

	fd_set allfds;

	FD_ZERO(&allfds);
	FD_SET(0, &allfds);   // set the stdin

	int maxfd = 0 + 1;

	struct timeval timeout;


	while (1)
	{
		timeout.tv_sec = 2;
		timeout.tv_usec = 0;     // set the timeout
		
		FD_ZERO(&allfds); //   000000
		FD_SET(0, &allfds); // 100000
		int ret = select(maxfd, &allfds, NULL, NULL, &timeout);
		if (-1 == ret) {
			fprintf(stderr, "Error from select\n");			
		} else if (0 == ret) {
			printf("Nothing to report\n");
			// logrotate
		} else {
			printf("%d file descriptors ready\n", ret);

			int modified = FD_ISSET(0, &allfds);
			printf("modified: %d\n", modified);

			char buffer[100];
			int nread = read(0, buffer, 100);
			if (-1 == nread) {
				perror("failed to read");
			} else {
				buffer[nread] = '\0';
				printf("received %s\n", buffer);
				if (strncmp(buffer, "quit", 4) == 0)
					break;
			}
		}
	}

	return 0;
}

