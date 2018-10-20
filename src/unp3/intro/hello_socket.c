#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>    // IPPROTO_TCP

// int socket(int domain, int type, int protocol);

int
main(int argc, const char *argv[])
{
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("socket() init successfully !\n");

    printf("AF_UNIX: %d\n", AF_UNIX);    // the historical Unix name
    printf("AF_LOCAL: %d\n", AF_LOCAL);  // the POSIX name
    printf("AF_INET: %d\n", AF_INET);
    printf("AF_INET6: %d\n", AF_INET6);
    printf("AF_IPX: %d\n", AF_IPX);
    // printf("AF_NETLINK: %d\n", AF_NETLINK);
    // printf("AF_PACKET: %d\n", AF_PACKET);
    printf("AF_ROUTE: %d\n", AF_ROUTE);
    // printf("AF_KEY: %d\n", AF_KEY);

    printf("SOCK_STREAM: %d\n", SOCK_STREAM);    // 1
    printf("SOCK_DGRAM: %d\n", SOCK_DGRAM);      // 2
    printf("SOCK_RAW: %d\n", SOCK_RAW);          // 3
    printf("SOCK_SEQPACKET: %d\n", SOCK_SEQPACKET);  // 5
    // printf("SOCK_PACKET: %d\n", SOCK_PACKET);    // Linux supports a new socket type,
                                                 // that provides access to the datalink

    printf("IPPROTO_TCP: %d\n", IPPROTO_TCP);    // 6
    printf("IPPROTO_UDP: %d\n", IPPROTO_UDP);    // 17
    printf("IPPROTO_SCTP: %d\n", IPPROTO_SCTP);  // 132

    exit(EXIT_SUCCESS);
}
