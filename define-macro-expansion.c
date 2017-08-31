/*
The macro arguments are not evaluated before macro expansion.
*/

#include <stdio.h>

#define MULTIPLY(a, b) a*b

int
main(void)
{
    // The macro is expended as 2 + 3 * 3 + 5, not as 5 * 8
    printf("%d", MULTIPLY(2+3, 3+5));
    return 0;
}


/*
code@lab:~/debug$ gcc -o define-macro-expansion define-macro-expansion.c 
code@lab:~/debug$ ./define-macro-expansion 
16
*/