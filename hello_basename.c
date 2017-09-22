#include <stdio.h>
#include <string.h>
#include <libgen.h>  /* comment here, the prog may crash. */


// char * basename (const char *filename)


// The GNU version of the [basename] function returns the last component of the path
// in filename. This function is the preferred usage, since it does not modify the argument,
// filename, and respects trailing slashes.


// char * basename (char *path)

// This is the standard XPG defined [basename]. It is similar in spirit to the GNU version,
// but may modify the [path] by removing trailing '/' bytes. If the [path] is made up entirely
// of '/' bytes, then "/" will be returned. Also, it path is NULL or an empty string string,
// then "." is returned. The prototype for the XPG version can be found in libgen.h.

int
main(int argc, char *argv[])
{
    char *prog = basename(argv[0]);
    // char *path = dirname(argv[0]);

    if (argc < 2)
    {
        fprintf(stderr, "Usage %s <arg>\n", prog);
    }

    return 0;
}