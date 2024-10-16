#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main() {

	int n = 4;
	puts("we're going to fork!");
	pid_t pid = fork();

	if(pid < 0) {
		perror("Unable to fork process");
		return 1;
	}

	//child
	if(pid == 0) {
		puts("I am the child!");
        
		n++;
		printf("%d\n", n);
		// sleep(1);
	} else {
		//parent
        // sleep(0.1);  // help 1.1

		puts("I am the parent");
		n *= 2;
		printf("%d\n", n);
		waitpid(pid, NULL, 0);
		// wait(NULL);
	}
	
	return 0;

}


/* 
		The wait will implicitly wait for one of its children finishes execution while waitpid will explicitly
		wait for a process to finish with a specified pid
	*/


/*
	1. No, no order for parent and child. run in parallel
	2. Looks nothing different. Parents are more likely to be faster than children， parent more likely to exit before child
	3. parent must wait child
*/