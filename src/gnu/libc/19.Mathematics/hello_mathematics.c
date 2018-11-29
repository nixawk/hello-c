// Mathematics

// This chapter contains information about functions for performing
// mathermatical computations, such as trigonometric functions. Most of these
// functions have prototypes declared in the header file math.h. The
// complex-valued functions are defined in complex.h.

// All mathematical functions which take a floating-point argument have three
// variants, one each for double, float, and long double arguments. The
// double versions are mostly defined in ISO C89. The float and long double
// versions are from the numeric extensions to C included in ISO C99. 

#include <math.h>
#include <stdio.h>

void sin_usage(void)
{
	double x = 30.0;
	double s = sin(x);

	printf("sin(30.0) = %lf\n", s);
}

int main(void)
{
	sin_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Mathematics.html#Mathematics
// https://www.gnu.org/software/libc/manual/html_node/Mathematical-Constants.html#Mathematical-Constants
// https://www.gnu.org/software/libc/manual/html_node/Trig-Functions.html#Trig-Functions
// https://www.gnu.org/software/libc/manual/html_node/Inverse-Trig-Functions.html#Inverse-Trig-Functions
// https://www.gnu.org/software/libc/manual/html_node/Exponents-and-Logarithms.html#Exponents-and-Logarithms
