#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

/*
    Two signal handler => Answer Time. answer No

    `pause` to make sure the order


    add sleep(1) in Line 40 to demonstrate without pause we will lose signal

*/
void answerTime(int signo){
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("The time is: %s", asctime(timeinfo));
}

void answerHomeWork(int signo){
    printf("No\n");
}

int main(){
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid > 0){
        // this is parent
        signal(SIGINT, answerTime);

        pause();
        printf("Have you finished your homework?\n");
        // sleep(1);
        kill(pid, SIGINT);
        
        wait(NULL);

    }else if (pid == 0){
        // this is child
        signal(SIGINT, answerHomeWork);
        
        printf("What's the time ?\n");
        kill(parent, SIGINT);

        pause();  

    }else{
        fprintf(stderr, "fork failed");
    }

}

// If we do not pause here, the child process will terminate, and the SIGINT lost from parent
