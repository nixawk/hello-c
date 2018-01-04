#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

#define FORK_PROCESSES_NUM 10

void
wait_usage(void)
{
    int i;                 /* count of fork processes */
    pid_t childpid;        /* pid of child process */

    setbuf(stdout, NULL);  /* Turn stdout cache off */

    for (i = 0; i < FORK_PROCESSES_NUM; i++)
    {
        switch (fork())
        {
            case -1:
                perror("fork");
                exit(EXIT_FAILURE);

            case 0:  /* child process*/
                printf("child processID: %d\n", getpid());
                exit(EXIT_SUCCESS);

            default: /* parent process */
                break;

                // if (wait(NULL) == -1)
                // {
                //     perror("wait");
                //     exit(EXIT_FAILURE);
                // }

                // printf("parent processID: %d\n", getpid());
                // exit(EXIT_SUCCESS);
        }
    }

    for (;;)  /* Parent waits for each child to exit */
    {
        childpid = wait(NULL);
        if (childpid == -1)
        {
            if (errno == ECHILD)
            {
                printf("No more children - bye !\n");
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }

        printf("wait() returned child PID %d\n", childpid);
    }

}

int
main(int argc, char *argv[])
{
    wait_usage();
    return 0;
}


// http://man7.org/linux/man-pages/man2/waitpid.2.html