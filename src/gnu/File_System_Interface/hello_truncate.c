#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


// int truncate (const char *filename, off_t length)

// The [truncate] function changes the size of filename to length.
// If length is shorter than the previous length, data at the end
// will be lost. The file must be writable by the user to perform
// this operation.

// If [length] is longer, holes will be added to the end. However,
// some systems do not support this feature and will leave the file
// unchanged.

// The return value is 0 for success, or -1 for an error.


void
truncate_usage(void)
{
    int err;

    err = truncate("/tmp/testfile", 1024 * 1024);  // resize to (1 MB)
    if (err != 0)
    {
        fprintf(stderr, "truncate() failed: %s\n", strerror(errno));
        exit(1);
    }
}


int
main(void)
{
    truncate_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/File-Size.html