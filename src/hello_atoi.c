#include <stdlib.h>
#include <stdio.h>

/*

int atoi(const char *str)

converts the string argument str to an integer (type int).

str - This is the string representation of an integral number.

This function returns the converted integral number as an int value.
If no valid conversion could be performed, it returns zero.

*/

int main(void)
{
    char sn[] = "123a456";
    int n;

    n = atoi(sn);
    if (n != 0)
        printf("String: %s -> Integer: %d", sn, n);  // output: 123
    return 0;
}
