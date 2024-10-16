#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    // attempt to open a file that does not exist
    FILE* file = fopen("missingno", "r");
    if (file == NULL) {
        perror("unable to open file");
        return 1;
    }
    fclose(file);



    /* 
        TODO: write to a file of your choice using fopen and fprintf
    */
    FILE* file2 = fopen("example.txt", "w");
    int numbers[8] = {1, 2, 3, 4, 5,6, 7, 8};
    for(int i = 0; i < 8; i++){
        // fwrite(numbers, sizeof(int), 8, file2);
        fprintf(file2, "%d", numbers[i]);
        // fprintf generally use for the text file and fwrite generally use for a binary file.
        // using command xxd to see binary file
    }

    // using "for" for fwrite it still be in the buffer!
    
    fclose(file2);
    // after fclose there will be all there, before this, nothing in file 




    /* 
        TODO: read from a file of your choice using fopen and fscanf
    */
    FILE* file3 = fopen("read.txt", "r");
    if (file3 == NULL) {
        perror("unable to open file");
        return 1;
    }

    char buffer[100];
    while (fscanf(file3, "%s", buffer) == 1){
        printf("%s ", buffer);
    }

    fclose(file3);


    

    /* 
        TODO: write to stdout and stderr using fprintf
    */

    fprintf(stderr,"HELP!");

    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
    for (int i = 0; i < 10; i++){
        fprintf(stdout, "%d", nums[i]);
        // see the difference for stdout and stderr (when sleep)
        sleep(1);
    }
   
    return 0;
}
