/*Nmae - Dolly Sidar
 Roll no -  2019034 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int n; // num of philosopher and fork
//semaphore structure declaration
struct my_semaphore
{
    pthread_mutex_t lock;  // declaring mutex lock
    int value;            // semaphore value
};
struct my_semaphore sauce; //declaring sauce bowl semaphore (assuming sauce as representation of pair of sauce bowl)
// philo structure declaration which will store the info of philosopher
struct philo
{
    int n;  //philospher
    struct my_semaphore left;    //left hand fork
    struct my_semaphore right;  //right hand fork
};

// declartion of  all the function which is going to be used
int sem_init(struct my_semaphore *s, int v);
int sem_wait(struct my_semaphore *s);
int sem_signal(struct my_semaphore *s);
void signal(struct my_semaphore *s);
void eat(int phil);
void *philosopher(void *data);

// Driver code
int main()
{

    printf("NUMBER : ");
    scanf("%d", &n);        //taking input of number of philosophers and chopstick
    struct my_semaphore chopstick[n]; // creating a array of chopstick of size n

    int i;
    pthread_t tid[n];

    sem_init(&sauce, 1);    //initializing sauce semaphore with value 1

    for (int i = 0; i < n; i++)
        sem_init(&chopstick[i], 1);     //initializing each chopstick semaphore with value 1

    struct philo data[n]; //creating array of philo structure of size n which will store the data of philosophers

    for (i = 0; i < n; i++)
    {
        data[i].n = i; //initializing philosophers number
        data[i].left = chopstick[i]; //intializing left hand fork
        data[i].right = chopstick[(i + 1) % n]; //intializing right hand fork
        pthread_create(&tid[i], NULL, philosopher, (void *)&data[i]); // calling the function philosopher() from pthread_create and passing it the address of an integer variable which refers to the philosopher number.
    }

    for (i = 0; i < n; i++)
        pthread_join(tid[i], NULL); //wait for completion of threads
}

//the function sem_init is used to initialize the semaphore
int sem_init(struct my_semaphore *s, int v)
{
    s->value = v;
    int pm = pthread_mutex_init(&s->lock, NULL); //initializing mutex lock
    if (pm != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }

}

//the sem_wait function is used to checks if the resource is available and if it is available, the resource is allocated to the philosopher by decrementing the value of semaphores . If all the resources are allocated i.e semaphore value is <0 it will try again m again until an unless the value of semaphore become >0
int sem_wait(struct my_semaphore *s)
{   
   
    while(s->value <= 0)
    {
        continue;
    }
    int d = 1;
    while( d!=0){
        d = pthread_mutex_trylock(&s->lock); // The pthread_mutex_trylock() function shall return zero if a lock on the mutex object referenced by mutex is acquired
    }
    s->value--;
    pthread_mutex_unlock(&s->lock);
}

//the sem_signal is used to free the semaphores by calling the sem_signal() so that the other threads get the chance to use the resources
int sem_signal(struct my_semaphore *s)
{   
    int d=1;
    while( d!=0){
        d = pthread_mutex_trylock(&s->lock);
    }
    s->value++;
    pthread_mutex_unlock(&s->lock);
}

// the eat function is used to represent which forks are used by philosopher to eat
void eat(int phil)
{
    printf("Philosopher %d is eating using forks %d and %d\n", phil, phil, (phil + 1) % n);
}

void *philosopher(void *data)
{
    int phil = ((struct philo *)data)->n;
    while (1)
    {
        sem_wait(&sauce);
        sem_wait(&((struct philo *)data)->left);
        sem_wait(&((struct philo *)data)->right);

        eat(phil);  //calling eat function
        sleep(1); //sleep for 1 sec so that other thread would get a chance to run first

        sem_signal(&((struct philo *)data)->right);
        sem_signal(&((struct philo *)data)->left);
        sem_signal(&sauce);
    }
}
// signal function is used to print semaphore value for debugging
void signal(struct my_semaphore *s)
{
    printf("%d\n", s->value);
}