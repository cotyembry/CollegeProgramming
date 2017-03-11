#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define TRUE 1

int buffer[BUFFER_SIZE];
int test;

int item;

void * producer (void* arg);
void * consumer (void* arg);
void putItemIntoBuffer(int);
int removeItemFromBuffer(void);

int main(int argc, char *argv[]) {
  for(test = 0; test < BUFFER_SIZE; test++) {
  buffer[test] = 0;
  printf("%d was placed in buffer\n", buffer[test]);
}
   /* Loop counter */
   int i;

   /* Verify the correct number of arguments were passed in */
   if(argc != 4) {
      fprintf(stderr, "USAGE:./main.out <INT> <INT> <INT>\n");
   }

   int mainSleepTime = atoi(argv[1]); /* Time in seconds for main to sleep */
   int numProd = atoi(argv[2]); /* Number of producer threads */
   int numCons = atoi(argv[3]); /* Number of consumer threads */

   pthread_t producer_thread[numProd], consumer_thread[numCons];

   /* Initialize the semaphores and the counter */
 //  initializeData();

   /* Create the producer threads */
   for(i = 0; i < numProd; i++) {
      /* Create the thread */
      pthread_create(&producer_thread[i],NULL,producer, (void *)i);
    }

   /* Create the consumer threads */
   for(i = 0; i < numCons; i++) {
      /* Create the thread */
      pthread_create(&consumer_thread[i],NULL,consumer,(void *)i);
   }

   /* Sleep for the specified amount of time in milliseconds */
   sleep(mainSleepTime);

   /* Exit the program */
   printf("Exit the program\n");
   exit(0);
}


sem_t mutex = 1;
sem_t fillCount = 0;
sem_t emptyCount = BUFFER_SIZE;
int count = 0;

void * producer(void * arg) {
    while (TRUE) {
        item = rand();
        sem_wait(&emptyCount);
        sem_wait(&mutex);
        putItemIntoBuffer(item);
        printf("%d produced; %d thread\n", item, arg);
        sem_post(&mutex);
        sem_post(&fillCount);
    }
}
void putItemIntoBuffer(item) {
  buffer[count] = item;
  count++;
  int inc;
  for(inc = 0; inc < count; inc++) {
    printf("%d in buffer\n", buffer[inc]);
  }
}

void * consumer(void * arg) {
    while (TRUE) {
        sem_wait(&fillCount);
        sem_wait(&mutex);
        item = removeItemFromBuffer();
        sem_post(&mutex);
        sem_post(&emptyCount);
        //consumeItem(item);
        printf("%d consumed; %d thread\n", item, arg);
    }
}
int removeItemFromBuffer() {
  int temp = buffer[count-1];
  printf("%d was just consumed\n", temp);
  count--;
  buffer[count] = 0;
  return temp;
}