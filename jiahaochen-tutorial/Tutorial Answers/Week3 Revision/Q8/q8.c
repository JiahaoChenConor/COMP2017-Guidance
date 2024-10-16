#include<stdio.h>
#include<stdlib.h>
int my_strlen(const char* s){
    int i = 0;
    if (s){
        while (s[i] != '\0'){
            i++;
        }
    }else{
        return -1;
    }

    return i;
}

int substring(const char* line, const char* substr) {
    /*
        line:      r a c e c a r   len = 7
        substr:            c a r   len = 3
                   0 1 2 3 4 5 6                [0, 4]

        the possibilities for the starting index in `line` should in range [0, lineLen - substrLen] 
                
    */
    int line_len = my_strlen(line); 
    int substr_len = my_strlen(substr);

    int index = -1;

    for (int i = 0; i <= (line_len - substr_len); i++){
        int found = 1;

        for (int j = 0; j < substr_len; j++){
            if (line[i + j] != substr[j]){  // *(line + i + j) != *(substr + j)
                found = 0;
                break;
            }
        }

        if (found){
            index = i;
            break;
        }
    }

    return index;
}

int main(){
    printf("%d\n", substring("racecar", "car")); //4
    printf("%d\n", substring("telephone", "one")); //6
    printf("%d\n", substring("monkey", "cat")); //-1
    return 0;
}