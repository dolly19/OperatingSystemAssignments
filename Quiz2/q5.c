#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


// reader = 6 & writer =2

sem_t Writer;
pthread_mutex_t mutex;
int a = 1;
int readercount = 0;

void *writer(void *wc);
void *reader(void *rc);

int main()
{

    pthread_t read[6], write[2];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&Writer, 0, 1);

    int people[6] = {1, 2, 3, 4, 5, 6}; 

    for (int i = 0; i < 6; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&people[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&people[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        pthread_join(read[i], NULL);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&Writer);

    return 0;
}

void *writer(void *wc)
{
    sem_wait(&Writer);
    a = a * 3;
    printf("W%d modified to %d\n", (*((int *)wc)), a);
    sem_post(&Writer);
}

void *reader(void *rc)
{

    pthread_mutex_lock(&mutex);
    readercount++;
    if (readercount == 1)
    {
        sem_wait(&Writer);
    }
    pthread_mutex_unlock(&mutex);

    printf("R%d read as %d\n", *((int *)rc), a);

    pthread_mutex_lock(&mutex);
    readercount--;
    if (readercount == 0)
    {
        sem_post(&Writer);
    }
    pthread_mutex_unlock(&mutex);
}
