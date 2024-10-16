#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;


void * T1(void * arg) {
	printf("This comes first\n");
    sleep(3);
    sem_post(&s); // post

}

void * T2(void * arg) {
    sem_wait(&s);    // wait 
    printf ("This comes second\n");
		
}

int main() {
	

	sem_init(&s, 0, 0);

	pthread_t th[2];
	pthread_create(th+0, NULL, T1, NULL);
	pthread_create(th+1, NULL, T2, NULL);
	
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);

	return 0;
}