#include <stdio.h>

/*

union
    - all members share the same memory location.
    - size of a union is taken according the size of largest member in union.

*/

union endian {
    char ch;
    unsigned int i;
};


int
main(void)
{
    union endian e;

    e.i = 0x01020304;
    if (e.ch == 0x4) {
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }

    return 0;
}