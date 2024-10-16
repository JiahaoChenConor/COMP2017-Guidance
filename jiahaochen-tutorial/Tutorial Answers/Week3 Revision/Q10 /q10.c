#include<stdio.h>
#define BUFF_LEN 128
#include <string.h>

int decode_run(const char* tuples, unsigned len, char* res) { // Assuming res is large enough

    // (1,2) (2,2) (3,5) (4,2) (2,1) (3,1)
    //  d n

    int res_index = 0;
    for (int digit_index = 0, num_index = 1; digit_index < len && num_index < len && tuples[digit_index] != '\0' && tuples[num_index] != '\0'; digit_index += 2, num_index += 2){

        int num = tuples[num_index] - '0'; // remember to - '0',   *(tuples + num_index)
        char digit = tuples[digit_index];  // *(tuples + digit_index)

        // copy the "digit" for "num" times 
        while (num > 0){
            res[res_index++] = digit;
            num--;
        }

    }

    res[res_index] = '\0';
    return 0;

}


int encode_run(const char* sequence, unsigned len,
    char* buf, unsigned int buf_len) {
    
    if (!sequence || !buf){
        return -1;
    }

    memset(buf, 0, BUFF_LEN);

    int index_se = 0;
    int index_buf = 0;
    int count = 0;
    char prev = sequence[0];

    buf[index_buf] = sequence[0];
    index_buf++;

    while (index_se < len && index_buf < buf_len){
        if (sequence[index_se] == prev){
            count++;

        }else{
            buf[index_buf] = count + '0';
            index_buf++;
            count = 1;

            // add digit in buffer
            buf[index_buf] = sequence[index_se];
            index_buf++;
        }

        prev = sequence[index_se];
        index_se++;
    }

    buf[index_buf - 1] = '\0';
    return 0;
}

int main() {
    char encoded_run[128];
    const char* line_run = "1122333334423";
    // len include '\0'
    encode_run(line_run, 14, encoded_run, BUFF_LEN);
    printf("%s\n", encoded_run); // 225211 the number of digit
                                // 2 (1), 2 (2), 5 (3), 2 (4), 1 (2), 1 (3)
    // (1,2) (2,2) (3,5) (4,2) (2,1) (3,1)

    char decoded_run[128];
    decode_run(encoded_run, 13, decoded_run);
    printf("%s\n", decoded_run);

}
