#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>


/* Always add at least this many bytes when extending the buffer. */
#define MIN_CHUNK 64

/* Read up to (and including) a TERMINATOR from STREAM into *LINEPTR 
   + OFFSET (and null-terminate it). *LINEPTR is a pointer returned
   from malloc (or NULL), pointing to *N characters of space. It is
   realloc'd as necessary. Return the number of characters read (not
   including the null terminator), or -1 on error or EOF. On a -1
   return, the caller should check feof(), if not then errno has
   been set to indicate the error.
*/

int
getstr(lineptr, n, stream, terminator, offset)
    char **lineptr;
    size_t *n;
    FILE *stream;
    char terminator;
    int offset;
{
    int nchars_avail;     /* Allocated but unused chars in *LINEPTR. */
    char *read_pos;       /* Where we're reading into *LINEPTR. */
    int ret;

    if (!lineptr || !n || !stream)
    {
        errno = EINVAL;
        return -1;
    }

    if (!*lineptr)
    {
        *n = MIN_CHUNK;
        *lineptr = malloc(*n);
        if (!*lineptr)
        {
            errno = ENOMEM;
            return -1;
        }
    }

    nchars_avail = *n - offset;
    read_pos = *lineptr + offset;

    for (;;)
    {
        int save_errno;
        register int c = getc(stream);

        save_errno = errno;

        /* We always want at least one char left in the buffer, since we
           always (unless we get an error while reading the first char)
           NUL-terminate the line buffer. */

        assert((*lineptr + *n) == (read_pos + nchars_avail));
        if (nchars_avail < 2)
        {
            if (*n > MIN_CHUNK)
                *n *= 2;
            else
                *n += MIN_CHUNK;

            nchars_avail = *n + *lineptr - read_pos;
            *lineptr = realloc(*lineptr, *n);
            if (!*lineptr)
            {
                errno = ENOMEM;
                return -1;
            }
            read_pos = *n - nchars_avail + *lineptr;
            assert((*lineptr + *n) == (read_pos + nchars_avail));
        }

        if (ferror(stream))
        {
            /* Might like to return partial line, but there is no
               place for us to store errno. And we don't want to
               just lose errno. */
            errno = save_errno;
            return -1;
        }

        if (c == EOF)
        {
            /* Return partial line, if any. */
            if (read_pos == *lineptr)
                return -1;
            else
                break;
        }

        *read_pos++ = c;
        nchars_avail--;

        if (c == terminator)
            /* Return the line. */
            break;
    }

    /* Done - NUL terminate and return the number of chars read. */
    *read_pos = '\0';

    ret = read_pos - (*lineptr + offset);
    return ret;
}

int
getline_(lineptr, n, stream)
    char **lineptr;
    size_t *n;
    FILE *stream;
{
    return getstr(lineptr, n, stream, '\n', 0);
}

void
readline_demo(filename)
    const char *filename;
{
    FILE *stream = NULL;
    char *lineptr = NULL;
    size_t n;

    stream = fopen(filename, "r");
    if (stream == NULL)
    {
        printf("failed to fopen %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (getline_(&lineptr, &n, stream) != -1)
    {
        printf("[*] %s", lineptr);
    }

    if (fclose(stream) != 0)
    {
        printf("failed to fclose %s\n", filename);
        exit(EXIT_FAILURE);
    }
}


int
main(int argc, const char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("[*] Usage: %s <file1> <file2> ...\n", argv[0]);
        return -1;
    }

    for (i = 1; i < argc; i++)
    {
        readline_demo(argv[i]);
    }
}

// https://dev.w3.org/libwww/Library/src/vms/getline.c
// https://opensource.apple.com/source/cvs/cvs-19/cvs/lib/getline.c