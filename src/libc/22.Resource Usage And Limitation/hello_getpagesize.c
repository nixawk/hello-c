#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>

// Function: int getpagesize (void)

// The getpagesize function returns the page size of the process. This value is fixed
// for the runtime of the process but can vary in different runs of the application.

void getpagesize_usage(void)
{
	int n = getpagesize();
	printf("getpagesize() = %d\n", n);
}

int main(void)
{
	getpagesize_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#toc-Resource-Usage-And-Limitation-1
