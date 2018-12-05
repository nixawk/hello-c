#include <stdlib.h>
#include <stdio.h>

// This section describes functions for performing integer division.
// These functions are redundant when GNU CC is used, because in GNU
// C the ‘/’ operator always rounds towards zero. But in other C
// implementations, ‘/’ may round differently with negative arguments.
// div and ldiv are useful because they specify how to round the
// quotient: towards zero. The remainder has the same sign as the numerator.

// Data Type: div_t

// This is a structure type used to hold the result returned by the div
// function. It has the following members.

    // int quot - The quotient from the divsion.
    // int rem  - The remainder from the division.

// Function: div_t div(int numerator, int denominator)

// This function div computes the quotient and remainder from the division
// of numerator by denominator, returning the result in a structure of type
// div_t. If the result cannot be represented (as in a division by zero),
// the behavior is undefined.

// Data Type: ldiv_t
// Function: ldiv_t ldiv (long int numerator, long int denominator)

// Data Type: lldiv_t
// Function: lldiv_t lldiv (long long int numerator, long long int denominator)

// Data Type: imaxdiv_t
// Function: imaxdiv_t imaxdiv (intmax_t numerator, intmax_t denominator)

void div_usage(void)
{
	int x = 5, y = 2;
	div_t r = div(x, y);

	printf("r.quot = %d\n", r.quot);
	printf("r.rem  = %d\n", r.rem);
}

int main(void)
{
	div_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Integer-Division.html#Integer-Division
