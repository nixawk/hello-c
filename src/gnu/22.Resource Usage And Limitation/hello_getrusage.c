#include <sys/resource.h>
#include <stdio.h>

// Function: int getrusage (int processes, struct rusage *rusage)

// This function reports resource usage totals for processes specified by processes,
// storing the information in *rusage.

// In most system, processes has only two valid values:

// RUSAGE_SELF - Just the current process.
// RUSAGE_CHILDREN - All child processes (direct and indirect) that have already terminated.


void
getrusage_usage(void)
{
    struct rusage rusage;

    if (getrusage(RUSAGE_SELF, &rusage) == 0)
    {
        printf("rusage.ru_utime.tv_sec = %ld\n", rusage.ru_utime.tv_sec);
        printf("rusage.ru_utime.tv_usec = %d\n", rusage.ru_utime.tv_usec);
        printf("rusage.ru_stime.tv_sec = %ld\n", rusage.ru_stime.tv_sec);
        printf("rusage.ru_stime.tv_usec = %d\n", rusage.ru_stime.tv_usec);
    }
}


int
main(void)
{
    getrusage_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Resource-Usage-And-Limitation
// https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html