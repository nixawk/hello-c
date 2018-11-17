/*
 * assert -- expression verification macro.
 *
 * The assert() macro tests the given expression and if it is false, the
 * calling process is terminated. A diagnostic message is written to stderr and
 * the abort(3) function is called, effectively terminating the program.
 *
 * If expression is true, the assert() macro does nothing.
 * The assert() macro may be removed at compile time with the cc option -DNDEBUG
 */

// gcc -DNDEBUG hello_assert.c


#include <assert.h>
#include <stdio.h>


void assert_usage(void)
{
    int n;

    printf("[*] please a num: ");
    scanf("%d", &n);

    assert(n == 10);  /* gcc -DNDEBUG hello-assert.c */
    printf("[*] n = %d\n", n);
}


int main(void)
{
    assert_usage();
    return 0;
}

/*

$ gcc hello-assert.c
$ ./a.out
[*] please a num: 1
Assertion failed: (n == 10), function assert_usage, file hello-assert.c, line 26.
Abort trap: 6


$ gcc -DNDEBUG hello-assert.c
$ ./a.out
[*] please a num: 1
[*] n = 1

*/

