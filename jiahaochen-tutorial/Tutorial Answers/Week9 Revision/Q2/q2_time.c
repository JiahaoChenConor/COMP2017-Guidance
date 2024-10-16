#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define PARENT_MSG_1 ("Hi! Do you know what time it is?")
#define CHILD_MSG_1 ("The time is 8:30 !")
#define PARENT_MSG_2 ("Thank you!")

#define PROMPT ("PROMPT!")

int main() {
	
	
	int parent_to_child[2];
	int child_to_parent[2];
	pipe(parent_to_child);
	pipe(child_to_parent);
	pid_t pid = fork();
	
	if(pid > 0) {
        char buf_par[30];
		// 1. parent print "what time"
		printf("Parent: %s\n",PARENT_MSG_1); 
		// 2. parent notify child to answer
		write(parent_to_child[1], PROMPT, strlen(PROMPT)); //Write first after print
		// 6. read from child
        read(child_to_parent[0], buf_par, strlen(CHILD_MSG_1));
        printf("%s\n", buf_par);
	} else if (pid == 0) {
		char buf[8];// WAIT AND READ
		// 3. wait for parent to ask time. "prompt". blocking at here
		read(parent_to_child[0], buf, 8);
		// 4. print time
		printf("Child: %s\n", CHILD_MSG_1); //Print and then write back
		// 5. write back to parent
		write(child_to_parent[1], CHILD_MSG_1, strlen(CHILD_MSG_1));
		
	} else {
		fprintf(stderr, "Something broke with fork!\n");
	}
	
	return 0;
}

