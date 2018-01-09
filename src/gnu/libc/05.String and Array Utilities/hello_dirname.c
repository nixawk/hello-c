#include <string.h>
#include <libgen.h>
#include <stdio.h>

// char * dirname (char *path)

// The dirname function is the compliment to the XPG version of basename.
// It returns the parent directory of the file specified by path. If path
// is NULL, an empty string, or contains no ’/’ bytes, then "." is returned.
// The prototype for this function can be found in libgen.h.


void
dirname_usage(void)
{
    char *path = "/usr/bin/id";
    char *dirp = dirname(path);

    printf("path: %s\n", dirp);

    // Ubuntu 17.04 - Segmentation fault (core dumped)
}


int
main(void)
{
    dirname_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling