#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#ifndef MAXLINE
#define MAXLINE 255
#endif

// $ ./a.out ::1 8080

// $ lsb_release -a
// No LSB modules are available.
// Distributor ID: Ubuntu
// Description:    Ubuntu 18.04.1 LTS
// Release:    18.04
// Codename:   bionic


int
main(int argc, const char *argv[])
{
    int sockfd;
    ssize_t nread;
    char recvline[MAXLINE + 1];
    struct sockaddr_in6 servaddr;

    if (argc != 3)
    {
        printf("[*] %s <host-ipv6> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("[*] socket() - IPv6\n");
#endif

    sockfd = socket(AF_INET6, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    servaddr.sin6_family = AF_INET6;
    servaddr.sin6_port = htons(atoi(argv[2]));

#ifdef DEBUG
    printf("[*] inet_pton()\n");
#endif

    if (inet_pton(AF_INET6, argv[1], &servaddr.sin6_addr) <= 0)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("[*] connect()\n");
#endif

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("[*] connected to %s:%s\n", argv[1], argv[2]);

#ifdef DEBUG
    printf("[*] read() - while");
#endif

    while ((nread = read(sockfd, recvline, MAXLINE)) > 0)
    {
        recvline[nread] = 0;
        if (fputs(recvline, stdout) == EOF)
        {
            perror("fputs");
            exit(EXIT_FAILURE);
        }
    }

    if (nread < 0)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("[*] close()");
#endif

    close(sockfd);
    exit(EXIT_SUCCESS);
}

// reference
// https://www.systutorials.com/docs/linux/man/3-inet_pton/
