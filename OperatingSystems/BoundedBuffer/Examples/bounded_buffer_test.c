//Producer Consumer (Bounded Buffer Problem)
//It's not an infinite loop
//the producer should be ++, the consumer should be --

/* buffer.h */
typedef int buffer_item;
#define BUFFER_SIZE 5

/* main.c */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define RAND_DIVISOR 100000000
#define TRUE 1

/* The mutex lock */
//pthread_mutex_t mutex;
//******* ^^^ uncomment
sem_t mutex;


/* the semaphores */
sem_t full, empty;

/* the buffer */
buffer_item buffer[BUFFER_SIZE];

/* buffer counter */
int counter;

//pthread_t tid;       //Thread ID
//pthread_attr_t attr; //Set of thread attributes

void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */

void initializeData() {

   /* Create the mutex lock */
 //  pthread_mutex_init(&mutex, NULL);
   sem_init(&mutex, 0, 1);

   /* Create the full semaphore and initialize to 0 */
   sem_init(&full, 0, 0);

   /* Create the empty semaphore and initialize to BUFFER_SIZE */
   sem_init(&empty, 0, BUFFER_SIZE);

   /* Get the default attributes */
//   pthread_attr_init(&attr);

   /* init buffer */
   counter = 0;
}

/* Producer Thread */
void *producer(void *param) {
   printf("%d thread is in producer thread\n", param);
   buffer_item item;

   while(TRUE) {
      /* sleep for a random period of time 
      int rNum = rand(); // RAND_DIVISOR;
      sleep(rNum);
      */
      /* generate a random number */
      item = rand();
      printf("created %d to place in buffer\n", item);

      if(counter == BUFFER_SIZE) { //need to wait until a consumer needs data
         sem_wait(&empty); //this stops the producer thread to wait for an empty signal
      }

      //else add item to buffer

      /* acquire the empty lock 
      sem_wait(&empty);
      */

      /* acquire the mutex lock */
//      pthread_mutex_lock(&mutex);
      sem_wait(&mutex); //avail a race condition when adding to the buffer

      if(insert_item(item) == -1) {
         //fprintf(stderr, " Producer report error condition\n");
         printf("error in inserting\n");
      }
      else {
         printf("producer produced %d\n", item);
      }
      /* release the mutex lock */
//      pthread_mutex_unlock(&mutex);
      sem_post(&mutex);

      /* signal full */
      sem_post(&full); //this tells the consumer thread that there is things to consume
   }
}

/* Add an item to the buffer */
int insert_item(buffer_item item) {
   /* When the buffer is not full add the item
      and increment the counter*/
   printf("counter is %d\n", counter);
   if(counter < BUFFER_SIZE) {
      buffer[counter] = item;
      counter++;
      printf("I inserted %d into the buffer: counter is %d\n", item, counter);
      int v;
      for(v=0; v < BUFFER_SIZE; v++) {
         printf("buffer item = %d\n", buffer[v]);
      }
      return 0;
   }
   else { /* Error the buffer is full */
      printf("error inserting\n");
      return -1;
   }
}

/* Consumer Thread */  
void *consumer(void *param) {
   buffer_item item;
   printf("in consumer thread\n");

   while(TRUE) {
      /* sleep for a random period of time 
      int rNum = rand(); // RAND_DIVISOR
      sleep(rNum);
      */

      /* aquire the full lock */
      if(counter == 0) { //need to wait until counter is > 0
         sem_wait(&full); //this stops the consumer thread until the producer thread creates something to consume
         sem_post(&empty); //this signals the producer thread to create something
      }

      /* aquire the mutex lock */
//      pthread_mutex_lock(&mutex);
      sem_wait(&mutex);


      if(remove_item(&item) == -1) {
         printf("remove_item error\n");
      }
      else {
         printf("consumer consumed %d\n", item);
      }
      /* release the mutex lock */
//      pthread_mutex_unlock(&mutex);
      sem_post(&mutex);


      /* signal empty */
      sem_post(&full); //let another consumer continue
   }
}



/* Remove an item from the buffer */
int remove_item(buffer_item *item) {
   /* When the buffer is not empty remove the item
      and decrement the counter */
   if(counter > 0) {
      *item = buffer[(counter-1)];  //this was originally ******* *item = buffer[(counter-1)];
      counter--;
      return 0;
   }
   else { /* Error buffer empty */
      return -1;
   }
}

int main(int argc, char *argv[]) {
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
   initializeData();

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