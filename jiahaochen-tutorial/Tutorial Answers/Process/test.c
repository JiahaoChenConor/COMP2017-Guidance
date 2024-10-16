#define _POSIX_SOURCE
#define _POSIX_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

static void handler(int signo)
{
      pid_t        pid;
      int        stat;
      // zombine process
      while ((pid = waitpid(-1, &stat, WNOHANG)) > 0){
          printf("child %d terminated.\n", pid);
      }
             
 }

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork error:");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("I am child process.I am exiting.\n");
        int send_signal = kill(getppid(), SIGUSR1);
        if (send_signal == -1){
            perror("kill error");
        }
       
    }
    printf("I am father process.I will sleep two seconds\n");
    //等待子进程先退出
    sleep(2);
    //输出进程信息
    system("ps -o pid,ppid,state,tty,command");
    printf("father process is exiting.\n");
    return 0;
}
