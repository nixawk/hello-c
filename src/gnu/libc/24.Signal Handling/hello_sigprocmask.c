#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void
handler(int sig)
{
    printf("signal catched\n");
}

int
main(void)
{
    sigset_t newsig, oldsig;

    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    if (sigemptyset(&newsig) == -1)
    {
        perror("sigemptyset");
        exit(EXIT_FAILURE);
    }

    if (sigaddset(&newsig, SIGINT) == -1)
    {
        perror("sigaddset");
        exit(EXIT_FAILURE);
    }

    if (sigprocmask(SIG_BLOCK, &newsig, &oldsig) == -1)
    {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    if (raise(SIGINT) == -1)  // handler output nothing
    {
        perror("raise");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is sent\n");

    return 0;
}


// http://man7.org/linux/man-pages/man2/sigprocmask.2.html