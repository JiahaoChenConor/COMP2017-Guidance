#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

int cnt = 0;
atomic_int acnt = 0;
int mcnt = 0;

pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;

void* f(void* param) {
  for(int n = 0; n < 10000; ++n) {
    
    // race condition
    cnt++;

    // atomic operation
    atomic_fetch_add(&acnt, 1);
    
    // mutex => atomic
    pthread_mutex_lock(&mylock);
    mcnt++;
    pthread_mutex_unlock(&mylock);
    
  }

  return NULL;
}

int main(void) {
  pthread_t t[10];
  for (int i = 0; i < 10; i++) pthread_create(&t[i], NULL, f, NULL);
  for (int i = 0; i < 10; i++) pthread_join(t[i], NULL);
  printf("acnt = %u; cnt = %u; mcnt = %u\n", acnt, cnt, mcnt);
}