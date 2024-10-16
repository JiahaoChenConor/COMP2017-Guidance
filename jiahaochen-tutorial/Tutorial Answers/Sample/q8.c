#include <stdio.h>
#define SMALL -9999
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
    
    int row = -1;
    int column = -1;
    transfrom_1D_to_2D(index, w, h, &row, &column);
    float sum = 0;

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
    float max_sum = SMALL;
    for (int i = 0; i < w * h; i++){
        float sum = get_sum_neighbouring(array, i, w, h);
        if (sum > max_sum){
            max_sum = sum;
            transfrom_1D_to_2D(i, w, h, found_x, found_y);
            printf("%d\n", i);
        }
    }
}

int main(){
    float array[24];
    for (float i = 0; i < 24; i++){
        array[(int) i] = i;
    }

    int find_x = -1;
    int find_y = -1;
    get_hma(array, 6, 4, &find_x, &find_y);
    printf("x is %d, y is %d\n", find_x, find_y);
    return 0;
}
