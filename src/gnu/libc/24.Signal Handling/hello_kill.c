#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

/* signal handler function */

void
handler(int sig)
{
    if (sig == SIGINT)
    {
        printf("parent process receives SIGINT\n");
    }
}

int
main(void)
{
    pid_t ppid, cpid;

    /* register signal handler */

    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    /* create child process with fork() */

    switch (fork())
    {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        /* send SIGINT from child process to parent process */

        case 0:                /* child process */
            ppid = getppid();  /* get parent process id */
            printf(" child process sends SIGINT\n");
            kill(ppid, SIGINT);
            break;

        default:              /* parent process */
            break;
    }

    /* parent process waits child process */

    for (;;)  /* Parent waits for each child to exit */
    {
        cpid = wait(NULL);
        if (cpid == -1)
        {
            if (errno == ECHILD)
            {
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    exit(EXIT_SUCCESS);
}