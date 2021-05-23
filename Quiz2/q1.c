#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#define size 500

int main(){
    int fd1[2];
    int fd2[2];

    char input_str[500];
    pid_t pid;

    if (pipe(fd1) == -1)
    {
        perror("Pipe Failed");
        return 1;
    }
    if (pipe(fd2) == -1)
    {
        perror("Pipe Failed");
        return 1;
    }
   
    scanf("%[^\n]%*c", input_str);
    pid = fork();
    if (pid < 0)
    {
        perror("fork() error");
        return 1;
    }

    else if (pid > 0)
    //Parent process
    {
        char upper_str[500];
        close(fd1[0]); 
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);

        wait(NULL);

        close(fd2[1]);
        read(fd2[0], upper_str, size);
        printf("%s\n", upper_str);
        close(fd2[0]);
    }
    else
    // child process
    {
        close(fd1[1]);
        int j=0;
        char ch;
        char upper_str [500];
        read(fd1[0], upper_str, size);
        while (upper_str[j])
        {
            ch = upper_str[j];
            upper_str[j] = (char)toupper(ch);
            j++;
        }
        

        close(fd1[0]);
        close(fd2[0]);

        write(fd2[1], upper_str, strlen(upper_str)+1);
        close(fd2[1]);

        exit(0);
         }

    }
