#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void print_uptime(int signo){
    char buffer[99];
    memset(buffer, 0, 99);
    FILE* fp = fopen("/proc/uptime", "r");
    fread(buffer, 1, 99, fp);
    printf("%s", buffer);
    
}

void print_random_num(int signo){
   int randomData = open("/dev/urandom", O_RDONLY);
    if (randomData < 0)
    {
        // something went wrong
    }
    else
    {
        char myRandomData[4];
        ssize_t result = read(randomData, myRandomData, sizeof myRandomData);
        if (result < 0)
        {
            // something went wrong
        }
        printf("%d\n", (int*) myRandomData);
    }
    
}

void print_joke(int signo){
    printf("This is a joke\n");
}

void go_home(int signo){
    printf("Go Home\n");
    exit(0);
}

int main(){
    signal(SIGINT, print_uptime);
    signal(SIGUSR1, print_joke);
    signal(SIGUSR2, print_random_num);
    signal(SIGHUP, go_home);

    while(1){
        sleep(1);
    }

}