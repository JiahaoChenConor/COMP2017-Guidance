#define MAX_MSG_LEN 50
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

/*
    When forking, child process also copy the heap memory.
    and global memory out of range because char* song = {"Never", }
*/


void child_routine(int fd, int* child_fds) {
    // read messages from the parent and repeat them
    for (int i = 0; i < 5; ++i) {
        char msg[MAX_MSG_LEN] = {'\0'}; 
        read(fd, msg, MAX_MSG_LEN); 
        printf("Echoing: %s\n", msg);
    } 

    
    free(child_fds);
}

void parent_routine(int* child_fds) {
    // for every child
    for (int j = 0; j < 10; ++j) {
        // send heartwarming messages through the pipe to the child
        char song[5][50] = { "Never", "gonna", "give", "you", "up" }; 

        for (int i = 0; i < 5; ++i)
        {
            write(child_fds[j], song[i], MAX_MSG_LEN);
        }
    }

    free(child_fds);
    // destroy_dyn_arr(child_fds);
}

int main() {
    int* child_fds = malloc(sizeof(int) * 10);
    // create 10 child processes
    for (int i = 0; i < 10; ++i) {
        // create a pipe for commmunication (create a pipe for every child)
        int fd[2] = {0}; 
        pipe(fd);
        // fork
        pid_t pid = fork(); 
        if (pid < 0)
        {
            fprintf(stderr, "fork failed");
            return 1; 
        }
        // child process
        if (pid == 0) {
            child_routine(fd[0], child_fds);
            return 0; 
        }

        // parent process saves the fd for later communication
        else
        {
            // insert_dyn_arr(child_fds, fd[1]);
            child_fds[i] = fd[1];
        } 
    }

    // send messages from the parent to the child
    parent_routine(child_fds);
    return 0; 
}
