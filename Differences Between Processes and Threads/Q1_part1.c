/* Name: Dolly Sidar
   Roll_Number: 2019304 */


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int a = 10;
int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork() error");
    }
    else if (pid == 0)
    {
        //child process
        while (a != -90)
        {
            --a;
        }
        printf("Value returned by child process %d\n", a);
    }
    else
    {
        //parent process
        wait(NULL);
        while (a != 100)
        {
            ++a;
        }
        printf("Value returned by parent process %d\n", a);
    }
    return 0;
}
