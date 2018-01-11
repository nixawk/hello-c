#include <stdio.h>
#include <stdlib.h>

#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif

#ifndef OUT_FILE
#define OUT_FILE "t.out"
#endif

void
write_usage(const char *filename)
{
    FILE *stream;  /* file stream */
    size_t nread;  /* count of read */
    char *buf;     /* buffer */

    /* open a file stream */

    stream = fopen(filename, "r");
    if (stream == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    buf = (char *) malloc(BUF_SIZE);
    if (buf == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (!(feof(stream) || ferror(stream)))
    {
        nread = fread(buf, BUF_SIZE, 1, stream);  /* nread -> count of block */
        fwrite(buf, BUF_SIZE, nread, stdout);     /* output to console */
    }

    free(buf);

    if (fclose(stream) != 0)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}

int
main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("[*] Usage: %s <FILE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    write_usage(argv[1]);

    exit(EXIT_SUCCESS);
}