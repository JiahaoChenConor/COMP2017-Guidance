#include<stdio.h>
#include<string.h>
int best_argset(int n, int *argc, char*** argv){
    int max_index = -1;
    int max_len = -1;
    for (int i = 0; i < n; i++){
        int item_argc = *(argc + i);
        char** item_argv = *(argv + i);
        int total_char = 0;
        for (int j = 0; j < item_argc; j++){
            total_char += strlen(*(item_argv));
        }
        if (total_char >= max_index){
            max_index = i;
            max_len = total_char;
        }
    }

    return max_index;
}
