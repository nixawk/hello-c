#include <stdio.h>
#include <limits.h>

// The type int means that the variable is a integer.

// short
// short int
// signed short
// signed short int

// int
// signed
// signed int

// unsigned
// unsigned int

// long
// long int
// signed long
// signed long int

// unsigned long
// unsigned long int

// long long
// long long int
// signed long long
// signed long long int

void
int_sizeof(void)
{
    // The size of these objects are also machine-dependent.
    printf("sizeof(int) = %lu byte(s)\n", sizeof(int));
}

void
int_min_or_max(void)
{
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);
}

int
main(void)
{
    int_sizeof();
    int_min_or_max();

    return 0;
}

/*

$ ./a.out
sizeof(int) = 4 byte(s)   // 64 bit
INT_MIN = -2147483648
INT_MAX = 2147483647

*/

// https://en.wikipedia.org/wiki/C_data_types
// https://www.geeksforgeeks.org/data-types-in-c/
