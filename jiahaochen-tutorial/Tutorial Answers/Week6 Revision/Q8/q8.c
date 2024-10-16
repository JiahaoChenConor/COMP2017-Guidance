#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

volatile int end = 1;

void printTime(int signo){
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    
    printf("Current local time and date: %s", asctime (timeinfo) );

    // better to use write rather than printf and its friend
    // write() ==> better to use write, for convinence, here we just use printf
}

void stop(int signo){
    printf("\nShutting Down");
    end = 0;
}


int main ()
{
    signal(SIGUSR1, printTime);
    signal(SIGINT, stop);
  
    while (end){
        sleep(1);
    }
    return 0;

}


  /*
        SIGINT is the signal sent when we press Ctrl+C. T
        he default action is to terminate the process. 
        However, some programs override this action and handle it differently.    

        // when send SIGUSR1, use the number 10
        Linux:
        fg --> make the program run in the background to the front
    */