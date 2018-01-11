#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// int raise(int sig);

// The raise() function sends a signal to the calling process or thread.
// In a single-threaded program it is equivalent to

    // kill(getpid(), sig);

// In a multithreaded program it is equivalent to

    // pthread_kill(pthread_self(), sig);

// If the signal causes a handler to be called, raise() will return only
// after the signal handler has returned.

void
handler(int sig)
{
    if (sig == SIGINT)
    {
        printf("SIGINT catched\n");
    }
}

int
main(void)
{

    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    if (raise(SIGINT) != 0)
    {
        perror("raise");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// http://man7.org/linux/man-pages/man3/raise.3.html