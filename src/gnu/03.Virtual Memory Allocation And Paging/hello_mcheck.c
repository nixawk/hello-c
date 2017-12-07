#include <stdlib.h>
#include <stdio.h>
#include <mcheck.h>


// int mcheck (void (*abortfn) (enum mcheck_status status))

// Calling mcheck tells malloc to perform occasional consistency checks.
// These will catch things such as writing past the end of a block that
// was allocated with [malloc].

// The [abortfn] argument is the function to call when an inconsistency is 
// found. If you supply a null pointer, then mcheck uses a default function
// which prints a message and calls abort. The function you supply is called
// with one argument, which says what sort of inconsistency was detected; its
// type is described below.

// It is too late to begin allocation checking once you have allocated anything
// with malloc. So mcheck does nothing in that case.

// This function returns -1 if you call it too late, and 0 otherwise (when it
// is successful).

// The easiest way to arrange to call mcheck early enough is to use the option
// '-lmcheck' when you link your program; then you don't need to modify your
// program source at all. Alternatively you might use a debugger to insert a
// call to mcheck whenever the program is started, for example these gdb
// commands will automatically call mcheck whenever the program starts.


int
main(int argc, char *argv[])
{
    char *p;

    if (mcheck(NULL) != 0)
    {
        fprintf(stderr, "mcheck() failed\n");
        exit(EXIT_FAILURE);
    }

    p = malloc(32);

    fprintf(stderr, "About to free\n");
    free(p);

    fprintf(stderr, "About to free a second time\n");
    free(p);

    exit(EXIT_SUCCESS);
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Heap-Consistency-Checking
// http://man7.org/linux/man-pages/man3/mcheck.3.html