#include <stdlib.h>
#include <stdio.h>


// Function: double erand48 (unsigned short int xsubi[3])

// This function returns a double value in the range of 0.0 to 1.0 (exclusive),
// similarly to drand48. The argument is an array describing the state of the
// state of the random number generator.

// This function can be called subsequently since it updates the array to
// guarantee random numbers. The array should have been initialized before
// initial use to obtain reproducible results.


void
erand48_usage(void)
{
    int i;
    unsigned short int xsubi[3];
    double n;

    for (i = 0; i < 10; i++)
    {
        n = erand48(xsubi);
        printf("%d. random num: %f\n", i, n);
    }
}


int
main(void)
{
    erand48_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/SVID-Random.html#SVID-Random