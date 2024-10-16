#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ex1.

// int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
// for (int i = 0; i < 10; i++){
//     fprintf(stdout, "%d", nums[i]);
//     // see the difference for stdout and stderr (when sleep)
//     sleep(1);
// }


int main(){
    FILE *fp;

    if( (fp=fopen("data.txt","w")) == NULL ){
        puts("Fail to open file!");
        exit(0);
    }

    char* change = "hello";
    fputs(change, fp);
  
  	// if we comment next line ? what happens
    fflush(fp);
  
    sleep(10);
    fputs("Closing the file\n", stderr);
    fclose(fp);
    return 1;
}

