#include <stdlib.h>
#include <stdio.h>

// int atexit (void (*function) (void))

// The [atexit] function registers the function [function] to be called at
// normal program termination. The [function] is called with no arguments.

// The return value from [atexit] is zero on success and nonzero if the function
// cannot be registered.


void
atexit_callback(void)
{
    printf("call atexit callback function\n");
}


void
atexit_usage(void)
{
    if (atexit(atexit_callback) != 0)
    {
        fprintf(stderr, "atexit() failed\n");
    } else {
        printf("register atexit callback function\n");
    }
}


int main(int argc, char const *argv[]) {
    atexit_usage();
    printf("main function\n");

    return 0;
}

/*

$ ./a.out
register atexit callback function
main function
call atexit callback function

*/

// https://www.gnu.org/software/libc/manual/html_node/Cleanups-on-Exit.html