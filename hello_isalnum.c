#include <ctype.h>
#include <stdio.h>

int main()
{
    /* int isalnum(int c) - This function checks whether the passed character is alphanumeric. */

    /*
        char    hex     digit
        ----    ----    ------
        0       0x30    48
        9       0x39    57

        a       0x61    97
        z       0x7a    122
    */

    printf("%d\n", isalnum('0'));   // true
    printf("%d\n", isalnum(48));    // true

    printf("%d\n", isalnum(58));    // true ( chr(57) = 9 )
    printf("%d\n", isalnum('%'));   // false
    return 0;
}

// https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
