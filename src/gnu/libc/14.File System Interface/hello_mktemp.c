#include <unistd.h>
#include <stdio.h>


// char * mktemp (char *template)

// The [mktemp] function generates a unique file name by modifying template as described above.
// If successful, it returns template as modified. If mktemp cannot find a unique file name,
// it makes template an empty string and returns that. If template does not end with 'xxxxxx',
// mktemp returns a null pointer.

// int mkstemp (char *template)

// The [mkdtemp] function generates a unique file name just as [mktemp] does, but it also opens
// the file for you with open. If successful, it modifies template in place and returns a file
// descriptor for that file open for reading and writing. If [mkstemp] cannot create a uniquely-named
// file, If template does not end with 'XXXXXX', mkstemp returns -1 and does not modify template.

// char * mkdtemp (char *template)

// The [mkdtemp] function creates a directory with a unique name.


void
mktemp_usage(void)
{
    char *tempfile = mktemp("XXXXXX");
    if (tempfile != NULL)
    {
        printf("temp file: %s\n", tempfile);
    }
}


int
main(void)
{
    mktemp_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Temporary-Files.html#Temporary-Files
// http://man7.org/linux/man-pages/man3/mktemp.3.html