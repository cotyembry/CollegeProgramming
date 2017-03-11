//Commented by John Coty Embry
//code found at http://cboard.cprogramming.com/c-programming/161877-dining-philosophers-problem-using-tannenbaum's-solution.html
//this implementation doesn't give priority to the philosophers in the order in which they try to eat.
//they are only able to eat after a philosopher puts down both forks and satisfy the if condition in the test() function
//which says 1. they are hungry 2. the left fork is available and 3. the right fork is available

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
 
 
sem_t mutex;
sem_t S[N];
 
 
void * philospher(void *num);
void take_chopstick(int);
void put_chopstick(int);
void test(int);
 
 
int state[N];
int phil_num[N]={0,1,2,3,4}; //there are 5 philosphers
 
 
int main(){
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
 
    //here the semaphores are initialized
    for(i=0;i<N;i++)
        sem_init(&S[i],0,0);
    //here the threads are created
    for(i=0;i<N;i++){
        pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);
        printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);
}
 
 
void *philospher(void *num){
    while(1){
        int *i = num; //num is the philosopher doing this
        sleep(1);
            take_chopstick(*i);
        sleep(0);
            put_chopstick(*i);
    }
}
 
 
void take_chopstick(int ph_num){
    sem_wait(&mutex); //this is used to avoid an issue with multiple threads being assigned an incorrect state
    state[ph_num] = HUNGRY; //ph_num is the philosopher doing this so this is making that philosopher in the HUNGRY state
        printf("Philosopher %d is Hungry\n",ph_num+1); //has to be ph_num+1 since they start at 0
    test(ph_num); //here a check is done to see if the philosopher has the resources "forks" (both forks I might add) to be able to eat
    sem_post(&mutex);
    sem_wait(&S[ph_num]);
    //sleep(1);
}

//everytime this function is called it is protected by a mutex lock whether it is called by the put_fork function or by the take_fork function 
//this function is to check the philosopher in question to see if he is hungry, and the philosophers to the left and right are not eating
void test(int ph_num){ //ph_num is the philosopher in question
    if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
        state[ph_num] = EATING;
        //sleep(2);
            printf("Philosopher %d takes chopstick %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
            printf("Philosopher %d is Eating\n",ph_num+1);
        sem_post(&S[ph_num]);
    }
}
 
//here the "forks" are distributed among the other philosophers by checking the left philosopher and the right philosopher to see if they satisfy the test condition 
void put_chopstick(int ph_num){
    sem_wait(&mutex);
    state[ph_num] = THINKING;
        printf("Philosopher %d putting chopstick %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
        printf("Philosopher %d is thinking\n",ph_num+1);
    test(LEFT); //here the philosopher to the left of the current focus (ph_num) is checked to see if he is hungry and if he has the resources to be able to eat
    test(RIGHT); //here the philosopher to the right of the current focus (ph_num) is checked to see if he is hungry and if he has the resources to be able to eat
    sem_post(&mutex);
}