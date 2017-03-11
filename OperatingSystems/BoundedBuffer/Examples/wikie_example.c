#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define TRUE 1

//Author: John Coty Embry
//Class: Operating Systems
//Date: 10/4/15
//Bounded Buffer

sem_t mutex;
sem_t fillCount; //number of items in buffer available to be read
sem_t emptyCount; //number of available spaces that items could be written into
int count = 0;


int buffer[BUFFER_SIZE];
int test;

int item;

void * producer (void* arg);
void * consumer (void* arg);
void putItemIntoBuffer(int);
int removeItemFromBuffer(int arg);

int main(int argc, char *argv[]) {

	int numProd; //will be used to state the number of producer threads
	int numCons; //will be used to state the number of consumer threads

	/* Initialize the eemaphores */
	sem_init(&mutex, 0, 1);
	sem_init(&fillCount, 0, 1);
	sem_init(&emptyCount, 0, BUFFER_SIZE);

	for(test = 0; test < BUFFER_SIZE; test++) { //Initialize the buffer to be all 0's
		buffer[test] = 0;
	}
   /* Loop counter */
   long i;

	printf("Enter number of producer threads: ");
	scanf("%d",& numProd);
	printf("Enter number of consumer threads: ");
	scanf("%d",& numCons);
//	printf("\n");

   pthread_t producer_thread[numProd], consumer_thread[numCons]; //allocate the thread arrays

   /* Create the producer threads */
   for(i = 0; i < numProd; i++) {
      /* Create the thread */
		//arguments are as follows:
		//thread location, default attributes, where the created thread starts running, the thread argument
      pthread_create(&producer_thread[i],NULL,producer, (void *)i);
    }

   /* Create the consumer threads */
   for(i = 0; i < numCons; i++) {
      /* Create the thread */
      pthread_create(&consumer_thread[i],NULL,consumer,(void *)i);
   }

	for(i =0; i < numCons; i++) { //these next pthread_join calls let the main thread wait on the threads that were created before exiting the main thread
		pthread_join(consumer_thread[i], NULL);
	}

	for(i=0; i < numProd; i++) {
		pthread_join(producer_thread[i], NULL);
	}
   /* Sleep for the specified amount of time in milliseconds */
//   sleep(mainSleepTime);

   /* Exit the program */
   printf("Exit the program\n");
   exit(0);
}

int inc = 9;
void * producer(void * arg) {
	int temp = (long)arg;
	while (TRUE) {
		sem_wait(&emptyCount); //if the int is positive the counter is decreased by 1 and thread continues, if its zero the thread is suspended and put into the private semaphore queue to wait for a "sem_post(&emptyCount) in this case

		sem_wait(&mutex); //this mutex avoids a race condition when incrementing the buffer
		putItemIntoBuffer(temp); 
		sem_post(&mutex);
		sem_post(&fillCount);
    }
}
//arguments is the thread thats doing it
void putItemIntoBuffer(int arg) {
	inc++;
	item = inc;
	buffer[count] = item;
	count++;
	printf("%d was placed in buffer; %d thread\n", item, arg);
}

void * consumer(void * arg) {
	int temp = (long)arg;
	while (TRUE) {
		sem_wait(&fillCount); //if the int is positive the counter is decreased by 1 and thread continues, if its zero the thread is suspended and put into the private semaphore queue to wait for a "sem_post(&fillCount) in this case

		sem_wait(&mutex); //this mutex avoids a race condition
		item = removeItemFromBuffer(temp);
		sem_post(&mutex);
		sem_post(&emptyCount);

    }
}
int removeItemFromBuffer(int arg) {
	int temp = buffer[count-1];
	printf("%d was just consumed; %d thread\n", temp, arg);
	count--;
	buffer[count] = 0;
	return temp;
}
