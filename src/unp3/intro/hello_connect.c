#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// $ ./a.out xxx.xxx.xxx.xxx port

int
main(int argc, const char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr_in;

    if (argc != 3)
    {
        printf("[*] Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    servaddr_in.sin_family = AF_INET;
    servaddr_in.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr_in.sin_addr) <= 0)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // The client does not have to call bind before calling connect:
    // the kernel will choose both an ephemeral port and the source IP
    // address if necessary.
    if (connect(sockfd, (struct sockaddr *)&servaddr_in, sizeof(servaddr_in)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("[*] connected to %s:%s\n", argv[1], argv[2]);
    exit(EXIT_SUCCESS);
}