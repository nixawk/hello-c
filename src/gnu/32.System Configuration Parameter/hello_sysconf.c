#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>


// Function: long int sysconf (int parameter)

// This function is used to inquire about runtime system parameters.
// The parameter argument should be one of the '_SC_' sy,bols listed below.
// The normal return value from sysconf is the value you requested. A value of
// -1 is returned both if the implementation does not impose a limit, and in
// case of an error.

void
sysconf_usage(void)
{
    long lim = sysconf(_SC_ARG_MAX);
    errno = 0;

    if (lim == (long) -1) /* Call successded, limit determinate */
    {
        if (errno == 0)   /* Call succeeded, limit indeterminate */
        {
            printf("indeterminate");
        }
        else              /* Call failed */
        {
            perror("sysconf");
            exit(EXIT_FAILURE);
        }
    }
    printf("NAME_MAX = %ld\n", lim);
}


int
main(void)
{
    sysconf_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Sysconf