#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>


#define MSG_LENGTH (1024)
#define PARENT_MSG_1 ("Hi! Do you know what time it is?")
#define CHILD_MSG_1 ("The time is 8:30 !")
#define PARENT_MSG_2 ("Thank you!")

void tell_me(int signo) {
	//NOOP Just helps move the pause()
}

int main() {


  	signal(SIGINT, tell_me);
	char* shared = mmap(NULL, MSG_LENGTH*sizeof(char), PROT_READ|PROT_WRITE, 
		MAP_ANON|MAP_SHARED, -1, 0);
	strcpy(shared, PARENT_MSG_1);
	
	pid_t parent = getpid();
	pid_t p = fork();
	
	if(p == 0) {
        // pasue until the signal appears
		pause();
		// 4. child print
		printf("Child: %s\n", shared);
		// 5. copy mess in shared mem
		strcpy(shared, PARENT_MSG_2);
        // SIGINT is Crtl + C
		// 6. send signal to parent
		kill(parent, SIGINT);
		munmap(shared, MSG_LENGTH*sizeof(int));

	} else if(p > 0) {
		// 1. print Parent: Hi! Do you know what time it is?
		printf("Parent: %s\n", shared);
		// 2. copy child mess in shared memory
		strcpy(shared, CHILD_MSG_1);
		// 3. send signal to child
		kill(p, SIGINT);
		pause();
		printf("Parent: %s\n", shared);
		munmap(shared, MSG_LENGTH*sizeof(int));
	}
	
	return 0;
}

