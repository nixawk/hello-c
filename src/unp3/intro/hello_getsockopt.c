#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


void
hello_getsockopt(int sockfd)
{
    int optval;
    socklen_t optlen;

    optlen = sizeof(optval);
    if (getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen) == -1)
    {
        perror("getsockopt()");
        exit(EXIT_FAILURE);
    }

   printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));
}


void
hello_setsockopt(int sockfd)
{
    int optval;
    socklen_t optlen;

    optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen) == -1)
    {
        perror("setsockopt()");
        exit(EXIT_FAILURE);
    }
}


int
main(int argc, const char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
    {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    hello_getsockopt(sockfd);
    hello_setsockopt(sockfd);
    hello_getsockopt(sockfd);

    if (close(sockfd) == -1)
    {
        perror("close()");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

// references
// http://pubs.opengroup.org/onlinepubs/009695399/functions/getsockopt.html
// http://www.cs.cmu.edu/afs/cs/academic/class/15213-f00/unpv12e/sock/sockopts.c
// http://www.cs.fsu.edu/~xyuan/cop5570/examples/lect17/example5.c
// https://www.tldp.org/HOWTO/html_single/TCP-Keepalive-HOWTO/
// https://github.com/soarpenguin/code-sample-c/blob/master/keepalive.c
