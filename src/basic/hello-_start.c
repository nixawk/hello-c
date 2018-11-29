// $ gcc hello-_start.c -nostartfiles
// $ ./a.out
// custom program entry

// Tested on Ubuntu 17.04

#include <stdio.h>
#include <stdlib.h>

void program_entry(void);

void _start(void)
{
	program_entry();
}

void program_entry(void)
{
	printf("custom program entry\n");
	exit(0);
}

/*

// $ gcc program_entry.c -e __start
// $ ./a.out
// custom program entry

// Tested on Mac OSX

#include <stdio.h>

void program_entry(void);

void
_start(void)
{ 
    program_entry();
}

void
program_entry(void)
{
    printf("custom program entry\n");
}

*/
