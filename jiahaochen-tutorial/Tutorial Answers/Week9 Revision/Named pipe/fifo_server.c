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
    if(argc<2)                        
    {
        printf("./a.out fifoname, need specify the name of fifo\n");
        exit(1);
    }
    int ret = access(argv[1],F_OK);    
    if(ret==-1)                        
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
    int fd=open(argv[1],O_RDWR);    
                         
    while (1){
        char buf[LEN];
        read(fd,buf,sizeof(buf));
        printf("Server Receive: buf=%s\n",buf);  

    
        
        fgets(buf, LEN, stdin);
        write(fd,buf,LEN);           // send string

        sleep(2);  // make sure client read the mess rather than server itself
       
     
        
    }


    close(fd);
    return 0;
}