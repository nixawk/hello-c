#include <stdio.h>
#include <stdlib.h>


// int fclose (FILE *stream)

// This function causes stream to be closed and the connection to the corresponding
// file to be broken. Any buffered output is written and any buffered input is discarded.
// The [fclose] function returns a value of 0 if the file was closed successfully, and
// EOF if an error was detected.

// It is important to check for errors when you call fclose to close an output stream,
// because real, everyday errors can be detected at this time.
// For example, when fclose writes the remaining buffered output, it might get an error
// because the disk is full. Even if you know the buffer is empty, errors can still
// occur when closing a file if you are using NFS.

// int fcloseall (void)

void
fclose_usage(void)
{
    FILE *fp;

    fp = fopen("/etc/passwd", "r");
    if (fp == NULL)
    {
        printf("fopen() failed.\n");
        exit(0);
    }

    fclose(fp);
}


int
main(void)
{
    fclose_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Closing-Streams.html#Closing-Streams
// https://stackoverflow.com/questions/1954273/fclose-return-value-check
// https://stackoverflow.com/questions/11805758/fclose-always-returns-eof