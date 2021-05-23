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

   
    key = ftok(".", 65);

    
    msgid = msgget(key, 0666 | IPC_CREAT);
    int flag =0;
    int dlag =0;
    while(flag !=1 || dlag != 2){
    msgrcv(msgid, &message, sizeof(message), 1, IPC_NOWAIT);
    if (strcmp(message.mesg_text, "\1") == 0)
        flag = 1;
    else if(strcmp(message.mesg_text, "\2") == 0)
        dlag = 2;
    else
        printf( "%s \n", message.mesg_text);

    }

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}