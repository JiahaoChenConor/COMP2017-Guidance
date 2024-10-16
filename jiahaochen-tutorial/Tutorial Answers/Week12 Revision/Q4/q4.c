#include "thread_pool.h"

#define MAIN_THREAD_TIMEOUT (60)
#define N_JOBS (200)

struct work_data {
    uint32_t time;
    uint32_t work_id;
};

void mysleep(void* arg) {
    struct work_data* data = (struct work_data*) arg;
    printf("is working on job %u\n", data->work_id);
    fflush(stdout);
    sleep(data->time);
    free(data);
}


int main() {

    struct thread_pool* pool = thread_pool_new(8);

    for(size_t i = 0; i < N_JOBS; i++) {
        struct work_data* d = malloc(sizeof(struct work_data));
        d->time = 1;
        d->work_id = i;
        struct thread_job* job = thread_job_new(mysleep, d);
        thread_pool_execute(pool, job);
    }
    sleep(MAIN_THREAD_TIMEOUT);
    thread_pool_destroy(pool);
    puts("Finishing up now!");
    return 0;
}
