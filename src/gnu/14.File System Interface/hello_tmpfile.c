#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// FILE *tmpfile(void);


/* Define outside of namespace so the C++ is happy.  */
// struct _IO_FILE;

/* The opaque type of streams.  This is the definition used elsewhere.  */
// typedef struct _IO_FILE FILE;

#ifndef BUFSIZE
#define BUFSIZE 1024
#endif

void
tmpfile_usage(void)
{
    FILE *stream;
    char fdpath[BUFSIZE];  // path to fd
    char fnpath[BUFSIZE];  // path to filename

    stream = tmpfile();
    if (stream == NULL)
    {
        perror("tmpfile()");
        exit(EXIT_FAILURE);
    }

    printf("FILE._fileno = %d\n", stream->_fileno);
    printf("fileno(FILE) = %d\n", fileno(stream));

    sprintf(fdpath, "/proc/self/fd/%d", fileno(stream));
    memset(fnpath, 0, sizeof(fnpath));
    readlink(fdpath, fnpath, BUFSIZE);
    printf("filename: %s\n", fnpath);

    fclose(stream);
}


int
main(void)
{
    tmpfile_usage();
    return 0;
}


// $ ./a.out
// FILE._fileno = 3
// fileno(FILE) = 3
// filename: /tmp/tmpfXQWpDZ (deleted)

// http://man.he.net/?topic=tmpfile&section=all
// https://stackoverflow.com/questions/16424349/where-to-find-struct-io-file
// https://stackoverflow.com/questions/4862327/is-there-a-way-to-get-the-filename-from-a-file