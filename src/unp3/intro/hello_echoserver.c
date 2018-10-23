#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Besides running our client and server in their normal mode
// (type in a line and watch it echo), we examine lots of
// boundary conditions for this example:
// - what happens when the client and server are started;
// - what happens when the client terminates normally;
// - what happens to the client if the server process terminates
//   before the client is done;
// - what happens to the client if the server host crashes; and so on.


#define BACKLOG 10
#define BUFSIZE 255

// A signal is a notification to process that an event
// has occurred. Signals are sometimes called software
// interrupts. Signals usually occur asynchronously.
// By this we mean that a process doesn't know ahead
// of time exactly when a signal will occur.

// Signals can be sent:
// By one process to another process (or to itself)
// By the kernel to a process

// When a child process stops or terminates,
// SIGCHLD is sent to the parent process.
// The default response to the signal is to ignore it.
void
sig_tstp(int signum)
{
    printf("[!] SIGTSTP = %d (Ctrl-Z)\n", signum);
}


void
sig_chld(int signum)
{
    pid_t pid;
    int   stat;

    // pid = wait(&stat);
    // printf("[!] child %d terminated\n", pid);

    while((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("[!] child %d terminated\n", pid);
}


void
echo_handler(int sockfd)
{
    ssize_t nr;  /* num of read bytes */
    ssize_t nw;  /* num of wrire bytes */
    char buf[BUFSIZE];

    // How to handle client close with Ctrl+C ?

    // nr > 0
    // nr = 0
    // nr < 0

    while (1)
    {
again:
        nr = read(sockfd, buf, BUFSIZE);  /* read data from socket */
        if (nr > 0)
        {
            printf("[R] %s\n", buf);

            nw = write(sockfd, buf, nr);  /* write data into socket */
            if (nw < 0)
            {
                perror("write()");
                exit(EXIT_FAILURE);
            }
            printf("[W] %s\n", buf);
        }
        else if (nr < 0)
        {
            if (errno == EINTR)
                goto again;

            perror("read()");
            exit(EXIT_FAILURE);
        }
        else
        {
            break;    // Ctrl+C
        }
    }
}


void
echo_server(const int port)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr_in;

    listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenfd == -1)
    {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    {
        perror("setsockopt()");
        exit(EXIT_FAILURE);
    }

    servaddr_in.sin_family = AF_INET;
    servaddr_in.sin_port = htons(port);
    servaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *)&servaddr_in, sizeof(servaddr_in)) == -1)
    {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) == -1)
    {
        perror("listen()");
        exit(EXIT_FAILURE);
    }

    // 1. We must catch the SIGCHLD signal when forking child process.
    // 2. We must handle interrupted system calls when we catch signals
    // 3. A SIGCHLD handler must be coded correctly using waitpid to
    // prevent any zombies from being left around.

    if (signal(SIGCHLD, sig_chld) == SIG_ERR)
    {
        perror("signal() - SIGCHLD");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGTSTP, sig_tstp) == SIG_ERR)
    {
        perror("signal() - SIGSTOP");
        exit(EXIT_FAILURE);
    }

    printf("[*] echo server is listening on 0.0.0.0:%d\n", port);
    for (int addrlen = sizeof(servaddr_in);;)
    {
        connfd = accept(listenfd, (struct sockaddr *)&servaddr_in, &addrlen);
        if (connfd < 0)
        {
            if (errno == EINTR)
                continue;               /* back to for() */
            else
            {
                perror("accept()");
                exit(EXIT_FAILURE);
            }
        }

        switch(fork())
        {
            case 0:                     /* child process */
                close(listenfd);        /* close listening socket */
                echo_handler(connfd);   /* process the request */
                exit(0);                
                break;

            case -1:
                break;

            default:                    /* parent process */
                break;
        }

        close(connfd);  /* parent closes connected socket */
    }
}


int
main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("[*] Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    echo_server(atoi(argv[1]));
    exit(EXIT_SUCCESS);
}


// reference
// https://www.geeksforgeeks.org/c-program-not-suspend-ctrlz-pressed/
