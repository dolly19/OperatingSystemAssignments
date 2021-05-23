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
    struct sockaddr_in servaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    FILE *ptr = fopen("para2.txt", "r");
    char buf[500];
    if (ptr == NULL)
    {
        printf("no such file.");
        return 0;
    }

    while (fscanf(ptr, "%s", buf) != EOF)
    {
        sendto(sockfd, &buf, strlen(buf),
               MSG_CONFIRM, (const struct sockaddr *)&servaddr,
               sizeof(servaddr));
    }
    char a[3] = "\1";
    sendto(sockfd, &a, strlen(a),
           MSG_CONFIRM, (const struct sockaddr *)&servaddr,
           sizeof(servaddr));
    fclose(ptr);
    close(sockfd);
    return 0;
}