#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
// thinking = 2
// hungry = 1
// eating = 0

int state[5];
int phil[5] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[5];
void release_fork(int i);
void recieve_fork(int i);
void *Philosphers(void *num);
void Test(int i) ;
int main()
{

    int i;
    pthread_t id[5];
    sem_init(&mutex, 0, 1);

    for (i = 0; i < 5; i++)
        sem_init(&S[i], 0, 0);

    for (i = 0; i < 5; i++)
        pthread_create(&id[i], NULL, Philosphers, &phil[i]);

    for (i = 0; i < 5; i++)
        pthread_join(id[i], NULL);
}

void recieve_fork(int i)
{
    int x = 0;
    sem_wait(&mutex);
    x = x + 1;
    state[i] = 1;
    Test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
    sleep(x);
}

void *Philosphers(void *num)
{
    int *i = num;
    sleep(1);
    recieve_fork(*i);
    sleep(0);
    release_fork(*i);
}

void Test(int i)
{
    if (state[(i + 1) % 5] != 0 && state[i] == 1 && state[(i + 4) % 5] != 0)
    {

        state[i] = 0;
        int a = i + 1;
        int b = (i + 4) % 5 + 1;
        int c = i + 1;
        sleep(1);
        printf("P%d receives F%d,F%d\n", a, b, c);
        sem_post(&S[i]);
    }
}

void release_fork(int i)
{
    sem_wait(&mutex);
    state[i] = 2;
    Test((i + 4) % 5);
    Test((i + 1) % 5);
    sem_post(&mutex);
}