#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


struct mesg_buffer
{
    long mesg_type;
    char mesg_text[500];
} message;

int main()
{
    key_t key;
    int msgid;
    char buf [500];
    
    key = ftok(".", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    FILE *ptr = fopen("para1.txt", "r");
    if (ptr == NULL)
    {
        printf("no such file.");
        return 0;
    }
    while (fscanf(ptr, "%s", buf) != EOF){
        strcpy(message.mesg_text, buf);
        msgsnd(msgid, &message, sizeof(message), 0);
    }
        char a[3] = "\1";
        strcpy(message.mesg_text, a);
        msgsnd(msgid, &message, sizeof(message), 0);
        fclose(ptr);

        return 0;
}

   