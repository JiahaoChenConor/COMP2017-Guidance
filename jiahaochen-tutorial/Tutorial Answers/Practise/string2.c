#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 9999

int count_underline(char *string){
    int num = 0;
    while (*(string) != '\0'){
        if (isupper(*(string))){
            num++;
        }
        string++;
    }
    return num;
}


/*
    abcDeFg
    abc_de_fg
    When meets the first uppercase, 'D', move D and e one position back and make D lowercase, the new '_' has the offset 0, 'count' = 1
    When meest the second uppercase, 'F', move F and g two position back and make F lowercase, the new '_' has the offset 1. 'count' = 2
*/
char* transform(int num_underlines, char * string){
    char* new_string = (char*) malloc(sizeof(char) * strlen(string) + num_underlines + 1);
    memset(new_string, '\0', strlen(string));
    int count = 0;
    for (int i = 0; *(string + i) != '\0'; i++){
        char letter = *(string + i);
        if (isupper(letter)){
            count++;
            *(new_string + i + count) = tolower(*(string + i));
            *(new_string + i + count - 1) = '_';
        }
        else{
             *(new_string + i + count) = *(string + i);
        }
       
    }
    return new_string;
}

int main(){
    char string[MAX_LEN];
    while (NULL != fgets(string, MAX_LEN, stdin)){
        int num_underline = count_underline(string);
        char* new_string = transform(num_underline, string);
        puts(new_string);
        free(new_string);
        new_string = NULL;
    }

}
