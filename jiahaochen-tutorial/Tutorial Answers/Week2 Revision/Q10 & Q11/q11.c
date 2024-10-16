#include <stdio.h>
#define MAX_LEN (100)

int string_compare(const char* w1, const char* w2, unsigned int len){

    /*
        len = 3
        abc
        abcd
    */
    if (!w1 || !w2 || len < 0){
        fputs("invalid compare.", stderr);
        return -1;
    }

    // printf("%s, %s, len: %d\n", w1, w2, len);
    int index = 0;
    while (*(w1 + index) != '\0' && *(w2 + index) != '\0' 
            && *(w1 + index) == *(w2 + index)){
        index++;
    }

    // printf("index is :%d\n", index);
    return len == index;
};


int count_len(char* str){
    int count = 0;

    while (*str != '\0'){
        count++;
        str++;
    }

    return count;
}

int main(int argc, char* argv[]){
    char buffer[MAX_LEN];

    while (1)
    {   
        char* ret = fgets(buffer, MAX_LEN, stdin);
        
        if (NULL == ret || ret != buffer){
            break;
        }

        int exist = 0;
        int len = count_len(*(argv + 1));

        //stupid, we can split the string by space
        for (int i = 0; i < 100; i++){
            int found = string_compare(buffer + i, *(argv + 1), len);
            if (found){
                exist = 1;
                break;
             
            }
        }
        
        if (exist){
            printf("Found: %s", buffer);
        }

    }

    return 0;
}
