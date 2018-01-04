#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

// int execve(const char *filename, char *const argv[],  char *const envp[]);

// On success, execve() does not return, on error -1 is returned, and errno
// is set appropriately.

extern char **environ;

/* custom cmd data structure */

typedef struct {
    char *prog;  /* executable programe */
    char *argv;  /* program argv */
    int cmdlen;  /* command length */
} cmd;


/* Parse program from command line */

cmd
parse_command(char *command)  /* del command arguments */
{
    cmd c;       /* custom cmd data structure */

    c.cmdlen = strlen(command);

    if ((c.cmdlen = strlen(command)) <= 0)
    {
        perror("no available command");
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("cmdlen: %d\n", cmdlen);
#endif

    if ((c.prog = malloc(c.cmdlen)) == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    memset(c.prog, '\0', c.cmdlen);  /* clear buffer with 0*/
    strcpy(c.prog, command);

    if ((c.argv = strchr(c.prog, ' ')) != NULL)
    {
        *(c.argv) = '\0';

#ifdef DEBUG
    printf("cmdprog: %s\n", c.prog);
    printf("cmdarg : %s\n", c.argv + 1);
#endif

    }

    return c;
}

/* Execute program with execve */

void
execve_command(char *command)
{
    cmd c;
    c = parse_command(command);

    char *argv[] = {
        c.prog,
        NULL
    };

    switch (fork())
    {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        case 0:  /* child process */
            if (execve(c.prog, argv, environ) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
            break;

        default:
            if (wait(NULL) == -1)
            {
                perror("wait");
                exit(EXIT_FAILURE);
            }
            break;
    }
}

int
main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("[*] Usage: %s <prog> <prog> ...", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            printf("[cmd]: %s\n", argv[i]);
            execve_command(argv[i]);
            printf("\n");
        }
    }

    return 0;
}

/*

$ ./a.out "uname" "/usr/bin/uname"

[cmd]: uname
execve: No such file or directory

[cmd]: /usr/bin/uname
Linux

*/

// https://www.linuxquestions.org/questions/programming-9/how-do-you-execute-a-binary-file-from-within-a-c-program-4175526999/
// https://support.sas.com/documentation/onlinedoc/sasc/doc/lr2/execve.htm
// http://man7.org/linux/man-pages/man2/execve.2.html