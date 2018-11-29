#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>

void show_program_invocation_name(void)
{
	printf("program_invocation_name: %s\n", program_invocation_name);
	printf("program_invocation_short_name: %s\n",
	       program_invocation_short_name);
}

int main(void)
{
	show_program_invocation_name();
	return 0;
}

/*

$ /tmp/a.out 
program_invocation_name: /tmp/a.out
program_invocation_short_name: a.out

*/
