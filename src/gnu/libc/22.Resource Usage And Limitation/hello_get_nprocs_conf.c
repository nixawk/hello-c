#define _GNU_SOURCE
#include <sys/sysinfo.h>
#include <stdio.h>

// Function: int get_nprocs_conf (void)

// The get_nprocs_conf function returns the number of processors the operating system configured.

void
get_nprocs_conf_usage(void)
{
    int n = get_nprocs_conf();
    printf("get_nprocs_conf() = %d\n", n);
}


int
main(void)
{
    get_nprocs_conf_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#toc-Resource-Usage-And-Limitation-1