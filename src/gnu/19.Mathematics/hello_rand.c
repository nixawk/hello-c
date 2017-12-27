#include <stdlib.h>
#include <stdio.h>

// Macro: int RAND_MAX

// The value of this macro is an integer constant representing the largest
// value the rand function can return. In the GNU C Library, it is 2147483647,
// which is the largest signed integer representable in 32 bits. In other
// libraries, it may be as low as 32767.


// Function: int rand (void)

// The rand function returns the next pseudo-random number in the series.
// The value ranges from 0 to RAND_MAX.

void
rand_usage(void)
{
    int x = rand();

    printf("random MAX: %d\n", RAND_MAX);
    printf("random num: %d\n", x);
}


int
main(void)
{
    rand_usage();
    return 0;
}


// $ ./a.out
// random num: 16807
// $ ./a.out
// random num: 16807
// $ ./a.out
// random num: 16807


// https://www.gnu.org/software/libc/manual/html_node/ISO-Random.html#ISO-Random