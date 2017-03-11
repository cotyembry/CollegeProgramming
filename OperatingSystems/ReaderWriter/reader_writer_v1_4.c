#include <stdio.h>
#include <semaphore.h> 
#include <pthread.h> //this is to include the created threads that will be created in the main thread

//Author: John Coty Embry
//Date: 9/30/15
//Class: Operating Systems
//Program Comment: This program demonstrates the reader writer problem. It puts a reader preference spin on the issue so that if a reader has a lock on the resource, the writer cannot read the resource but more readers can read the resouce.

//most of the reader writer code came from here: https://en.wikipedia.org/wiki/Readers–writers_problem
//this site helped me write the main file: http://www.codingdevil.com/2014/04/c-program-for-reader-writer-problem.html by Umesh Toke
//I used the man page in the terminal to help me with pthread_create and to put the correct parameters
//This site helped with with declaring semaphores: http://www.csc.villanova.edu/~mdamian/threads/posixsem.html

//a good semaphore explanation found here: https://www.cs.mtu.edu/~shene/NSF-3/e-Book/SEMA/basics.html
//pthread_create explanation found at: http://www.amparo.net/ce155/thread-ex.html
//The pthread_create function is used to create new threads. It accepts a thread variable, a thread attribute, a start routine function, and an optional argument. To use default thread attributes, pass NULL as the second argument.
//After the thread has been succesfully created, it starts execution at the indicated start routine function. What is passed to the function is not the function name, but the address of the function type casted as a void pointer.
//Arguments can be passed to the thread using the fourth parameter to pthread_create. Again, a void pointer to the argument is passed. This void pointer should later be type casted back to its true type within the thread routine.

//The following variables are the semaphores that are used to help with the critical section and race condition issues
sem_t   resource; 
sem_t   mutex;
int     readcount = 0;

void* writer(void *arg); // I need to ask what the * after void stands for
void* reader(void *arg);

int main(void) {
    int i = 0, NumberofReaderThread = 0, NumberofWriterThread = 0;
    sem_init(&resource, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_t   Readers_thr[10], Writer_thr[10];
    printf("Enter number of Readers thread: 0 through 10 only.\n");
    scanf("%d",& NumberofReaderThread);

    if (NumberofReaderThread > 10) {
        printf("Error: too many threads chosed.\n");
        return 1;    
    } else if (NumberofReaderThread < 0) {
			printf("Error: you entered a negative number\n");
			return 1;
		}
    printf("Enter number of Writers thread: 0 through 10 only.\n");
    scanf("%d",& NumberofWriterThread);

    if (NumberofWriterThread > 10) {
        printf("Error: too many threads chosed.\n");
        return 1;    
    } else if (NumberofWriterThread < 0) {
			printf("Error: you entered a negative number\n");
			return 1;
		}
    for (i = 0; i < NumberofReaderThread; i++) {
        pthread_create(&Readers_thr[i], NULL, reader, (void *)i);
    }
    for (i = 0; i < NumberofWriterThread; i++) {
		printf("how many\n");
        pthread_create(&Writer_thr[i], NULL, writer, (void *)i);
    }
    for (i = 0; i < NumberofWriterThread; i++) {
        pthread_join(Writer_thr[i], NULL);
    }

    for (i = 0; i < NumberofReaderThread; i++) {
        pthread_join(Readers_thr[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&resource);
    return 0;
}

/* Note that:
   resource.P() is equivalent to wait(resource)
   resource.V() is equivalent to signal(resource)
   mutex.P() is equivalent to wait(mutex)
   mutex.V() is equivalent to signal(mutex)
*/

void* writer(void * arg) { 
    int temp = (int) arg;
//  <ENTRY Section>
    printf("writer %d is about to wait.\n", temp);
    sem_wait(&resource); //Lock the shared file for a writer
//  <CRITICAL Section>
    printf("writer %d writing in critical section.\n", temp);
    // Writing is done here

//  <EXIT Section>
    sem_post(&resource); //Release the shared file for use by other readers. Writers are allowed if there are no readers requesting it.
    printf("writer %d is out of critical section.\n", temp);
}

void* reader(void * arg) {
    int temp = (int) arg;
//   <ENTRY Section>
    sem_wait(&mutex); //Ensure that no other reader can execute the <Entry> section while you are in it 

    readcount++;//Indicate that you are a reader trying to enter the Critical Section

    if (readcount == 1) { //Checks if you are the first reader trying to enter CS
        sem_wait(&resource); //If you are the first reader, lock the resource from writers. Resource stays reserved for subsequent readers        
        printf("reader %d just locked resource from writers.\n", temp);
    }
    sem_post(&mutex); //Release <Entry> Section. Let other readers enter the <Entry> section, now that you are done with it. 

//  <CRITICAL Section>
    // Do the Reading
    // (Critical Section Area)
    printf("reader %d is reading in the critical section\n", temp);
//  <EXIT Section>
    sem_wait(&mutex); //Ensure that no other reader can execute the <Exit> section while you are in it
    printf("reader %d locked the exit section to avoid race condition.\n", temp);
    readcount--;//Indicate that you are no longer needing the shared resource. One less readers

        if (readcount == 0) { //Checks if you are the last (only) reader who is reading the shared file
            printf("This should print before a writer can get in critical section\n");
            sem_post(&resource); //If you are last reader, then you can unlock the resource. This makes it available to writers.
            printf("reader %d unlocked resource so now writers can use the resource.\n", temp);
        }
    sem_post(&mutex); //Let other readers enter the <Exit> section, now that you are done with it.
    printf("reader %d freed the exit section (solves race condition issue)\n", temp);
}
