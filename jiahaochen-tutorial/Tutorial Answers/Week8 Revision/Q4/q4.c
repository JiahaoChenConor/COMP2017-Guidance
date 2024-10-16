#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUF_SIZE 100
#define PROC_LIMIT 50

/*

    Try sleep 100 &, 100  , 3 (should be removed after 3 seconds)
*/
int main(void) {
    char buf[BUF_SIZE];
    char executable[BUF_SIZE];
    char arg[BUF_SIZE];

    pid_t pids[PROC_LIMIT]; // pid table
    size_t nproc = 0; // number of active processes

    while (1) {
        printf("> ");
        fgets(buf, BUF_SIZE, stdin);
        sscanf(buf, "%s %s", executable, arg);

        
        for (int i = 0; i < nproc; i++) {
			// WNOHANG => makes non-blocking 
            /*
                our process has other things that it needs to do. 
                We just want to collect the status of a dead process if there are any. 
                That's what WNOHANG is for. 
                It prevents wait()/waitpid() from blocking so that your process can go on with other tasks. 
                If a child died, its pid will be returned by wait()/waitpid() and your process can act on that. 
                If nothing died, then the returned pid is 0.
            */
            if (waitpid(pids[i], NULL, WNOHANG)) {
                printf("Removed PID %d\n", pids[i]);
                nproc--;
                memmove(pids+i, pids+i+1, nproc-i);

                // 1 2 3 4 5
                // remove 3   pids+i:3 4 5, pids+i+1:4 5, size=2. so 3 4 5 become 4 5 5
                // 1 2 4 5 5
                // size --
                // 1 2 3 5

            }
        }

        if (strcmp(executable, "exit") == 0) {
            break;
        }


        pid_t pid = fork();

        if (pid == 0) {
            sprintf(buf, "/usr/bin/%s", executable);
            if (execl(buf, executable, arg, (char*) NULL) == -1) {
                perror("exec failed");
                return 1;
            }
        } else {
			// fork return value for parent process is pid of child
			// add new process
            pids[nproc++] = pid;
            printf("Added PID %d\n", pid);
            printf("PID table\n");
            for (int i = 0; i < nproc; i++) {
                printf("%d\n", pids[i]);
            }
        }
    }
}


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUF_SIZE 100
/*

    Try sleep 100 &, 100  , 3 (should be removed after 3 seconds)
*/
int main(void) {
    char buf[BUF_SIZE];
    char executable[BUF_SIZE];
    char arg[BUF_SIZE];


    while (1) {
        printf("> ");
        fgets(buf, BUF_SIZE, stdin);
        sscanf(buf, "%s %s", executable, arg);

        if (strcmp(executable, "exit") == 0) {
            break;
        }

        

        pid_t pid = fork();

        if (pid == 0) {
            sprintf(buf, "/usr/bin/%s", executable);
            if (execl(buf, executable, arg, (char*) NULL) == -1) {
                perror("exec failed");
                return 1;
            }
        } else {
			wait(NULL);
        }
    }
}

