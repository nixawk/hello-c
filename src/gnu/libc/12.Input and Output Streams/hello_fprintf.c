#include <stdio.h>
#include <stdlib.h>

void
write(const char *filename)
{
    FILE *stream;  /* file stream */
    int cnt;       /* count of characters */

    stream = fopen(filename, "w");
    if (stream == NULL)
    {
        perror("freopen");
        exit(EXIT_FAILURE);
    }

    cnt = fprintf(stream, "%s", "hello, world\n");

    printf("%d characters are written\n", cnt);
    // fprintf(stdout, "%d characters are written\n", cnt);


    if (fclose(stream) != 0)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}

int
main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("[*] Usage: %s <FILE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    write(argv[1]);

    exit(EXIT_SUCCESS);
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Formatted-Output-Functions