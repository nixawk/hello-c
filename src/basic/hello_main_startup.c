#include <stdio.h>

/*

With GCC family of C compilers, we can mark some functions to execute before and after main().

    void constructor(void) __attribute__((constructor));
    void destructor(void) __attribute__((destructor));
*/

__attribute__((constructor))
void
constructor(void)
{
    printf("main constructor\n");
}


__attribute__((destructor))
void
destructor(void)
{
    printf("main destructor\n");
}


int
main(void)
{
    printf("main function block\n");
    return 0;
}


// https://stackoverflow.com/questions/2053029/how-exactly-does-attribute-constructor-work
// http://www.geeksforgeeks.org/functions-that-are-executed-before-and-after-main-in-c/