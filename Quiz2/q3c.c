#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 9080



int main()
{
  
    char buffer[500];
    struct sockaddr_in servaddr, cliaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

        if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    int bin = bind(sockfd, (const struct sockaddr *)&servaddr,
                    sizeof(servaddr)) ;
    if (bin < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;

    len = sizeof(cliaddr);
    int flag = 0;
    int dlag = 0;
    while (flag != 1 || dlag != 2)
    {
        n = recvfrom(sockfd, (char *)buffer, 500,
                     MSG_WAITALL, (struct sockaddr *)&cliaddr,
                     &len);
        if (strcmp(buffer, "\1") == 0)
            flag = 1;
        else if (strcmp(buffer, "\2") == 0)
            dlag = 2;
        else{
            buffer[n] = '\0';
            printf("%s\n", buffer);
        }
    }

    
    return 0;
}