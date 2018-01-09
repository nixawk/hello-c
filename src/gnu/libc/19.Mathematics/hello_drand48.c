#include <stdlib.h>
#include <stdio.h>

// Function: double drand48(void)

// This function returns a double value in the range of 0.0 to 1.0 (exclusive).
// The random bits are determined by the global state of the random number
// generator in the C library.

// Since the double type according to IEEE 754 has a 52-bit mantissa this means
// 4 bits are not initialized by the random number generator. These are (of 
// course) chosen to be the least significant bits and they are initialized to
// 0.

void
drand48_usage(void)
{
    int i;
    double n;

    for (i = 0; i < 10; i++)
    {
        n = drand48();
        printf("%d. random num: %f\n", i, n);
    }
}


int
main(void)
{
    drand48_usage();
    return 0;
}

// $ ./a.out
// 0. random num: 0.396465
// 1. random num: 0.840485
// 2. random num: 0.353336
// 3. random num: 0.446583
// 4. random num: 0.318693
// 5. random num: 0.886428
// 6. random num: 0.015583
// 7. random num: 0.584090
// 8. random num: 0.159369
// 9. random num: 0.383716

// https://www.gnu.org/software/libc/manual/html_node/SVID-Random.html#SVID-Random