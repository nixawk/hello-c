#define _GNU_SOURCE
#include <sys/sysinfo.h>
#include <stdio.h>


// Function: int get_nprocs (void)

// The get_nprocs function returns the number of available processors.

// Before starting more threads it should be checked whether the processors are
// already overused. Unix systems calculate something called the load average.
// This is a number indicating how many processes were running. This number is
// an average over different periods of time.


void
get_nprocs_usage(void)
{
    int n = get_nprocs();
    printf("get_nprocs() = %d\n", n);
}


int
main(void)
{
    get_nprocs_usage();
    return 0;
}