#include<stdio.h>
#include <string.h>
#define BUFF_LEN 128

int encode_run(const char* sequence, unsigned len,
    char* buf, unsigned int buf_len) {
    
    if (!sequence || !buf){
        return -1;
    }

    memset(buf, 0, BUFF_LEN);

    int index_se = 0;
    int index_buf = 0;

  
    int count = 0;      // the number of consecutive digits

    char prev = sequence[0];  // for the first one, we need ++, but it != prev, so set prev as itself

    while (index_se < len && index_buf < buf_len){
        // if the cur digit is the same with prev. count++
        if (sequence[index_se] == prev){
            count++;

        // otherwise, the end of consecutive digits, store it in buffer
        }else{
            buf[index_buf] = count + '0';// set how many number for one digit  1 + '0' = '1', the ASCII
            index_buf ++;
            // reset the count when meeting a different digit
            count = 1;
        }

        prev = sequence[index_se];
        index_se++;
    }

    buf[index_buf] = '\0';
    return 0;
}

int main() {
    char encoded_run[128];
    const char* line_run = "1122333334423";
    // len include '\0'
    encode_run(line_run, 14, encoded_run, BUFF_LEN);
    printf("%s\n", encoded_run); // 225211 the number of digit
                                // 2 (1), 2 (2), 5 (3), 2 (4), 1 (2), 1 (3)

}
