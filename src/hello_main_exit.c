#include <stdio.h>
#include <stdlib.h>


/*
[In C++], what is the different between exit(0) and return 0 ?

When exit(0) is used to exit from program, destructors for locally scoped non-static
objects are not called. But destructors are called if return 0 is used.
*/

void constructor(void) __attribute__ ((constructor));
void destructor(void) __attribute__ ((destructor));


void
constructor(void)
{
    printf("main constructor\n");
}


void
destructor(void)
{
    printf("main destructor\n");
}


int
main(void)
{
    printf("main - block\n");
    exit(0);
}

// http://www.geeksforgeeks.org/return-statement-vs-exit-in-main/