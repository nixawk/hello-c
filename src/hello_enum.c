#include <stdio.h>

/* Enumeration (or enum) is a user defined data type in C. */

/*
    1. Two enum keys can have same value.
    2. If not assign values to enum keys, the compiler by default assigns values starting from 0.
    3. All unassigned keys get value as value of previous key plus one.
    4. The value assigned to enum keys must be some integeral constant,
*/

enum days {Mon, Tue, Wed, Thur, Fri, Sat, Sun};
enum enum_value {A = 0, B = 0, C = 0};
enum enum_order {x = 2, y, z};  /* y == 3, z == 4 */

int
main(void)
{
    enum days nday;
    nday = Tue;

    printf("Day number: %d\n", nday);

    switch (nday)
    {
        case Mon:
            printf("Today is Monday\n");
            break;
        case Tue:
            printf("Today is Tuesday\n");
            break;
        case Wed:
            printf("Today is Wesdenday\n");
            break;
        case Thur:
            printf("Today is Thursday\n");
            break;
        case Fri:
            printf("Today is Friday\n");
            break;
        case Sat:
            printf("Today is Saturday\n");
            break;
        case Sun:
            printf("Today is Sunday\n");
            break;
        default:
            printf("unknown day\n");
    }
    return 0;
}