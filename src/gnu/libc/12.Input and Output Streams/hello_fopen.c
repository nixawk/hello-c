// Opening a file with the fopen function creates a new stream and establishes
// a connection between the stream and a file.

// Function: FILE * fopen (const char *filename, const char *opentype)


#include <stdio.h>
#include <stdlib.h>

void
fopen_usage(void)
{
    FILE *s;

    s = fopen("/etc/passwd", "r");
    if (s == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    printf("FILE._fileno = %d\n", s->_fileno);

    if (fclose(s) != 0)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}

int
main(void)
{
    fopen_usage();
    return 0;
}

// http://man7.org/linux/man-pages/man3/fopen.3.html
