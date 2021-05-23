/* Name: Dolly Sidar
   Roll_Number: 2019304 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int a = 10;
void *child_thread(void *args)
{
    while (a != -90)
    {
        --a;
        printf("%d ",a);
        
    }
    printf("Value returned by child process %d\n", a);
}

int main()
{
    pthread_t id;
    pthread_create(&id, NULL, child_thread, NULL);
    while (a != 100)
    {
        ++a;
        printf("%d ", a);
    }
    printf("Value returned by parent process %d\n", a);

    pthread_join(id, NULL);
    pthread_exit(NULL);
    return 0;
}

