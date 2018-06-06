/*
The tokens passed to macros can be concatenated using operator ## called Token-Pasting operator.
*/

#include <stdio.h>

#define merge(a, b) a##b

int
main(void)
{
    printf("%d\n", merge(12, 34));  // output: 1234
    return 0;
}