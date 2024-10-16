#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define MAX_RIDERS 100

pthread_mutex_t mutex;	
sem_t riders_waiting; //multiplex
sem_t bus_arrival;   //bus
sem_t bus_depart;    //all_aboard
int waiting = 0;


/*void board(){
	sem_wait(&riders_waiting);
	return;
}*/

void * rider(){
	while(1){		
		sem_wait(&riders_waiting);   // capacity is 50 
		pthread_mutex_lock(&mutex);		// get mutex
		waiting = waiting + 1;          // wait + 1
		printf("RIDERS: riders waiting = %d \n",waiting);
		sleep(1);
		pthread_mutex_unlock(&mutex); 		
        // Two possiblities: 1. wait bus arrived, blocking, and line	51 send post, 2. line 39 restore	
        // a lot of people waiting here, once bus arrived, one of thread can continue, the others still blocking
        // once 1 passenger step into the bus, it will sem_post(&bus_arrival), and another passenger can go into the bus.
		sem_wait(&bus_arrival);	       
		sem_post(&riders_waiting);     


		// once this print, that means the bus have arrived and get the mutex, other thread can not enter line 25
        // and bus_arrival will only  
		printf("RIDER: bus is here. \n riders waiting: %d \n",waiting--);					
		sleep(1);
		if(waiting ==0){
			sem_post(&bus_depart); // if all passengers enter into the bus, post bus_depart, bus can depart, line 52 continue
		}else{
			sem_post(&bus_arrival);// otherwise, next loop, in order to continue at line 29, restore bus_arrival
		}	
	}
}

void * bus(){	
	while(1){
		//sem_wait(&riders_waiting);
		//printf("Bus arrived \t waiting: %d\n",waiting);						
		pthread_mutex_lock(&mutex);	

		if(waiting >0){
		sem_post(&bus_arrival); // one bus arrived, so bus s += 1
		sem_wait(&bus_depart);  // blocking, wait until meet 50 people to depart
		}

        // if no waiting passengers, depart immediately
		printf("BUS: departing! \n riders waiting: %d \n",waiting);
		pthread_mutex_unlock(&mutex);		

		sleep(1);
	}
}


void main(int argc, char * argv[]){
	pthread_t  riders [MAX_RIDERS];
	pthread_t b1;
	pthread_mutex_init(&mutex,NULL);

	sem_init(&riders_waiting,0,50);
	sem_init(&bus_arrival,0,0);
	sem_init(&bus_depart,0,0);
	int t_id;
	pthread_create(&b1,NULL,bus,NULL);
	for(t_id=0; t_id< MAX_RIDERS ;t_id++){
		pthread_create(&riders[t_id],NULL,rider,NULL);
		//sleep(1);
	}
	//pthread_create(&b1,NULL,bus,NULL);
	//pthread_create(&t1,NULL,bus,(void*)&i);
	pthread_join(b1,NULL);
}