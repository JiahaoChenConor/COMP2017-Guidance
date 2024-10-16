#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* file = fopen("number", "w");
    int numbers[8] = {1, 2, 3, 4,5 ,6, 7, 8};
    for(int i = 0; i < 8; i++){
        fwrite(numbers, sizeof(int), 8, file);
        // flush every time it gets to 4096
    }
    
    // write binary representation not readable
    // using command xdd to see

    // using "for" for fwrite it still be in the buffer!
    
    fclose(file);
    // after fclose there will be all there, before this, nothing in file 
    fgetc(stdin);
    return 0;
}
