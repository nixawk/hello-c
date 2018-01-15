#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void
handler(int signum)
{
    if (signum == SIGALRM)
    {
        printf("SIGALRM received.\n");
        exit(EXIT_SUCCESS);
    }
}

int
main(void)
{
    unsigned int seconds = 5;   /* alarm seconds */

    if (signal(SIGALRM, handler) == SIG_ERR)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    alarm(seconds); /* alarm - set an alarm clock for delivery of a signal */

    for (;;)
    {
        printf("waiting for signal...\n");
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}

/*

$ ./a.out
waiting for signal...
waiting for signal...
waiting for signal...
waiting for signal...
waiting for signal...
SIGALRM received.

*/

// http://man7.org/linux/man-pages/man2/alarm.2.html