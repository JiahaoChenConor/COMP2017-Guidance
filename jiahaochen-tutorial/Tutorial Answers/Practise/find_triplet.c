#include "find_triplet.h"

/*
* The parameter is the address of the struct thread data TDATA.
* Within the struct,the initial state is:
* thread_id is set for the thread.It is in range[0,number_of_threads-1] 
* results is allocated to be as large as array
* results_size is -1 
* The return value is the address this thread's own TDATA.
*/
void *find_triplet_thread_worker(void* args){
    TDATA *tdata = (TDATA *)args;
    // Every thread should process len_chunk elements in array except the last thread
    int len_chunk = array_size / number_of_threads;

    int start = (tdata->thread_id) * len_chunk;
	// If end is the last thread, it should deal with rest items(maybe not 3:LEN_CHUNCK)
    // otherwise, the length of item must be 3
	int end = (tdata->thread_id) == number_of_threads - 1 ? array_size : (tdata->thread_id + 1) * len_chunk;

    int max_num_res = (end - start) / 3 + 1;

    int* results = (int*) malloc(max_num_res * sizeof(int));
    int num_results = 0;
    for (int i = start; i < end; i++){
        if (start % 3 == 0 && start + 2 < end){
            if (*(array) == *(array + 1) - 1 && *(array + 1) == *(array + 2) - 1){
                *(results + num_results) = start;
                num_results ++;
            }
        }
    }
    
    return NULL;
}
