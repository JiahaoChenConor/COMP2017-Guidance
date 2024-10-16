#include <time.h>
#include <stdio.h>
int main(void) {
    const clock_t tick = clock();
    int ops = 0;
    for (int i = 0; i < 10000000; i++) {
        ops += i;
    }
    const clock_t tock = clock();
    printf("Time elapsed: %fs\n", (double) (tock - tick) / CLOCKS_PER_SEC);
    return 0;


    // struct timespec tstart={0,0}, tend={0,0};
    // clock_gettime(CLOCK_MONOTONIC, &tstart);

    // int ops = 0;
    // for (int i = 0; i < 10000000; i++) {
    //     ops += i;
    // }

    // clock_gettime(CLOCK_MONOTONIC, &tend);
    // printf("some_long_computation took about %.5f seconds\n",
    //        ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
    //        ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
}

// time ./mutex
// 4000000

// real 0m0.420s    wall clock
// user 0m0.999s    total CPU time used,. see user > real(clock) so multiple cores run simultaneously.
// sys 0m1.234s     system calls or kernal
