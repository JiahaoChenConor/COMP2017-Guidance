#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t ping_lock;
sem_t pong_lock;

void * T1(void * arg) {
	for (;;) {
		sem_wait(&ping_lock); // wait ping become 1    ==> 1. first           3. wait
		printf("ping\n");
		sleep(1);
		sem_post(&pong_lock); // make pong become 1    ==> 2. pong += 1
	}
}

void * T2(void * arg) {
	for (;;) {
		sem_wait(&pong_lock); // wait pong become 1     ==> 3. pong = 0
		printf ("pong\n");
		// sleep one second                             
		sleep(1);                            
		sem_post(&ping_lock); // make ping become 1
	}
}

int main() {
	
	// ping to go first
	sem_init(&ping_lock, 0, 1);
	sem_init(&pong_lock, 0, 0);

	pthread_t th[2];
	pthread_create(th+0, NULL, T1, NULL);
	pthread_create(th+1, NULL, T2, NULL);
	
	// wait for threads to finish
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);

	return 0;
}