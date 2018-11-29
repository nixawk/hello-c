#define _GNU_SOURCE
#include <sys/sysinfo.h>
#include <stdio.h>

// Function: long int get_phys_pages (void)

// The get_phys_pages function returns the total number of pages of physical memory
// the system has. To get the amount of memory this number has to multiplied by the
// page size.

// Function: long int get_avphys_pages (void)

// The get_avphys_pages funcrtion returns the number of available pages of physical
// memory the system has. To get the amount of memory this number has to multiplied
// by the page size.

void get_phys_pages_usage(void)
{
	long int n = get_phys_pages();
	printf("get_phys_pages() = %ld\n", n);
}

int main(void)
{
	get_phys_pages_usage();
	return 0;
}
