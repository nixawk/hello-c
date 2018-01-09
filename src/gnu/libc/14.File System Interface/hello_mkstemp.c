#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// int mkstemp(char *template);

// The mkstemp() function generates a unique temporary filename from  tem-
// plate,  creates and opens the file, and returns an open file descriptor
// for the file.

void
mkstemp_usage(void)
{
    int fd;
    char template[] = "/tmp/mkstemp_template.XXXXXXXXX";

    fd = mkstemp(template);
    if (fd == -1)
    {
        perror("mkstemp()");
        exit(EXIT_FAILURE);
    }

    printf("Generated filename : %s\n", template);

    if (close(fd) == -1)
    {
        perror("close()");
        exit(EXIT_FAILURE);
    }
}


int
main(void)
{
    mkstemp_usage();
    return 0;
}

// $ ./a.out
// Generated filename : /tmp/mkstemp_template.2AkTTz

// http://man.he.net/?topic=mkstemp&section=all