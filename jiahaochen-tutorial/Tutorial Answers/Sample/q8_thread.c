#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define SMALL -9999
#define THREAD_NUM 4
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

typedef struct thread_info{
    int thread_id;
    int chunk_len;
    int array_size;
    float* max_sum;
    float * array;
    int* found_x;
    int* found_y;
    int w;
    int h;
}THREAD_INFO;

void transfrom_1D_to_2D(int index, int w, int h, int* row, int* column){
    *row = index / w;
    *column = index % w;
}

void transfrom_2D_to_1D(int row, int column, int w, int h, int* index){
    if (row < 0 || row >= h || column < 0 || column >= w){
        *index = -1;
        return;
    }
    *index = row * w + column;
}

float get_sum_neighbouring(float *array, int index, int w, int h){
    // int centre = *(array + index);
    printf("%d\n", __LINE__);
    int row = -1;
    int column = -1;
    printf("%d\n", __LINE__);
    transfrom_1D_to_2D(index, w, h, &row, &column);
    float sum = 0;
    printf("%d\n", __LINE__);
    for (int i = row - 1; i <= row + 1; i++){
        for (int j = column - 1; j <= column + 1; j++){
            int index_in_array = -1;
            transfrom_2D_to_1D(i, j, w, h, &index_in_array);
            // The index is valid
            if (index_in_array != -1){
                sum += array[index_in_array];
            }
        }
    }
    return sum / 9;
}

void * thread_work(void* argv){
    pthread_mutex_lock(&lock);
    THREAD_INFO* info = (THREAD_INFO *)argv;
    float* array = info->array;
    float* max_sum_ptr = info -> max_sum;
    // start index is the thread_id * the length of every chunk
    int start = (info->thread_id) * (info->chunk_len);
    // end index has two possibilities (end index is the next index of last element)
    // 1. not the last chunk, then the end index is "start + length of chunk"
    // 2. it is the last chunk, then the end index is array_size.
    int end = (info->thread_id) == THREAD_NUM - 1 ? (info->array_size) : (info->thread_id + 1) * (info->chunk_len);

    for (int i = start; i < end; i++){
        float sum = -1;
        printf("%d\n", __LINE__);
        sum = get_sum_neighbouring(array, i, info->w, info->h);
        printf("%d\n", __LINE__);
        // critial part, update the max_sum
        // update the found_x and found_y
        
        if (sum > *max_sum_ptr){
            
            *max_sum_ptr = sum;
            transfrom_1D_to_2D(i, info->w, info->h, info->found_x, info->found_y);
            
        }
        
        printf("%d\n", __LINE__);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
    
}

void get_hma(float *array, int w, int h, int *found_x, int *found_y){
    // NULL is returned in found x or found y if there is an error. 
    // The error can arise if the input array is NULL, 
    // dimensions are 0, or found x or found y are NULL values themselves.
    if (array == NULL || w <= 0 || h <= 0){
        found_x = NULL;
        found_y = NULL;
    }

    // For the 1-D array, we can compute the line and column according to the index
    // eg. width is num of elements in one row, and height is how many rows

    // Solution 1. use 4 threads to calculate the sum of every positions, that is array_len/4 is CHUNK length,
    //              but we compare with the res with the sum every time, lock the res.


    float max_sum = SMALL;
    int total_size = w * h;
    int chunk_len = total_size / THREAD_NUM;

    THREAD_INFO infos[4];
    pthread_t threads[4];

    for (int i = 0; i < 4; i++){
        THREAD_INFO* info_i = &infos[i];
        info_i->thread_id = i;
        info_i->chunk_len = chunk_len;
        info_i->array_size = w * h;
        info_i->max_sum = &max_sum;
        info_i->array = array;
        info_i->found_x = found_x;
        info_i->found_y = found_y;
        info_i->w = w;
        info_i->h = h;
        printf("%d\n", __LINE__);
        pthread_create(&threads[i], NULL, thread_work, info_i);
    }

    for (int i = 0; i < 4; i++){
        pthread_join(threads[i], NULL);
    }

  
}

int main(){
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int find_x = -1;
    int find_y = -1;
    get_hma(array, 3, 3, &find_x, &find_y);
    printf("x is %d, y is %d\n", find_x, find_y);
    return 0;
}
