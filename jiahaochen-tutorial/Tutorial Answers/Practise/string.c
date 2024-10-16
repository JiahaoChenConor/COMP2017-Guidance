#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 9999

/*
    Example: abc_def_g_hi
    After the first '_', start moving according to the number of '_'
    'd' move one place forward
    'g' move two places forward
    'h' move three places forward
    SO need to count the number of '_' and the first letter after '_' should be uppercase

    Until the terminating character '\0'
*/
void transform(char *string){
    int count_underline = 0;
    int start_move = 0;
    int upper = 0;

    while (*(string) != '\0'){
        if (*(string) == '_'){
            start_move = 1;
            upper = 1;
            count_underline++;
        }
        else if (start_move){
            if (upper){
                *(string - count_underline) = toupper(*(string));
                upper = 0;
            }else{
                *(string - count_underline) = *(string);
            }
        }
        string ++;
    }
    *(string - count_underline) = '\0';
}


int main(){
    char input[MAX_LEN];
    while (NULL != fgets(input, MAX_LEN, stdin)){
        transform(input);
        puts(input);
    }
}





