#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LEN 1024
int main(int argc,char *argv[])
{
    if(argc<2)                            // pass fifoname
    {   
        printf("./a.out fifoname\n");
        exit(1);
    }   

    int ret = access(argv[1],F_OK);        // file exists ?
    if(ret==-1)                            // If not create
    {   
        int r = mkfifo(argv[1],0664);
        if(r==-1){
            perror("mkfifo");
            exit(1);
            }
        else{
            printf("fifo creat success!\n");
        }
    }

    int fd = open(argv[1],O_RDWR);    // open with W R

    if(fd==-1){
            perror("open");
        exit(1);
    }

    while(1){     
        char buf[LEN];
        fgets(buf, LEN, stdin);
        write(fd,buf,LEN);           // send string


        sleep(2);        // to make sure server read
     
        read(fd,buf,sizeof(buf));
        printf("Client Receive: buf=%s\n",buf);  

        

    }
    close(fd);                            // close
    return 0;
}