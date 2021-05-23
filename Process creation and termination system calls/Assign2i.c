#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


int main(){
    int fd;
    char buf[10000];
    char *op[500];
    char *final[3000];
    char a;
    float avg;
    pid_t pid = fork();
    if (pid  < 0){
        perror("fork() error");}
    else if(pid == 0){
        //child process
        write(1,"****Child Process****\n",sizeof("****Child Process****"));
        fd = open("details.csv", O_RDONLY);
        if (!fd)
        {
            perror("file doesn't exit");
            return 0;
        }
        while (a != '\n')
        {
            read(fd, &a, 1);
        }
        int s = read(fd, buf, 10000);
        char *pch = NULL;
        pch = strtok(buf, "\r\n");
        int i = 0;
        while (pch != NULL)
        {
            op[i] = pch;
            pch = strtok(NULL, "\r\n");
            i++;
        }
        int z = 0;
        int j = 0;
        while (op[z] != NULL)
        {
            char *cch = NULL;
            cch = strtok(op[z], ",");
            while (cch != NULL)
            {
                final[j] = cch;
                cch = strtok(NULL, ",");
                j++;
            }
            z++;
        }
        int A1, A2, A3, A4;
        
        write(1, "Student of sec A and their average marks\n", sizeof("Student of sec A and their average marks"));
         for (int i = 2; i < 2400; i = i + 6)
        {
            int val = strcmp(final[i-1],"A");
            if (val == 0)
            {
                
                printf("%s ", final[i - 2]);
                float avvy =0;
                for (int j = i; j < i + 4; j++)
                {
                    avvy = avvy + atof(final[j]);
                }
                avg = avvy / 4;
            
                printf("%.2f\n",avg);
                

            }
        }

       exit(0); 
    }
    else{
        //parent process
        int state;
        waitpid(pid, &state, 0);
        write(1, "****Parent Process****\n", sizeof("****Parent Process ****"));
        fd = open("details.csv", O_RDONLY);
        if (!fd)
        {
            perror("file doesn't exit");
            return 0;
        }
        while (a != '\n')
        {
            read(fd, &a, 1);
        }
        int s = read(fd, buf, 10000);
        char *pch = NULL;
        pch = strtok(buf, "\r\n");
        int i = 0;
        while (pch != NULL)
        {
            op[i] = pch;
            pch = strtok(NULL, "\r\n");
            i++;
        }
        int z = 0;
        int j = 0;
        while (op[z] != NULL)
        {
            char *cch = NULL;
            cch = strtok(op[z], ",");
            while (cch != NULL)
            {
                final[j] = cch;
                cch = strtok(NULL, ",");
                j++;
            }
            z++;
        }
        int A1, A2, A3, A4;
        
        write(1, "Student of sec B and their average marks\n", sizeof("Student of sec B and their average marks"));
        for (int i = 2; i < 2400; i = i + 6)
        {
            int val = strcmp(final[i - 1], "B");
            if (val == 0)
            {
                
                printf("%s ", final[i - 2]);
                float avvy = 0;
                for (int j = i; j < i + 4; j++)
                {
                    avvy = avvy + atof(final[j]);
                }
                avg = avvy / 4;
                printf("%.2f\n", avg);
                
            }
        }
    }
       
return 0;
}
