/*
 * Type
 *
 * Objects, functions and expressions have a property called type, which 
 * determines the interpretation of the binary value stored in object or
 * evaluated by the expression.
 *
 * The C type system consists of the following types:
 * 
 * - the type void
 * - basic types
 *   - the type char
 *   - signed integer types
 *     - standard: signed char, short, int, long, long long
 *     - extended: implementation-defined, e.g. __uint128
 *   - unsigned integer types
 *     - standard: Bool, unsigned char, unsigned short,
 *                 unsigned int, unsigned long, unsigned long long
 *     - extended: implementation-defined, e.g. __uint128
 * - floating types
 *     - real floating types: float, double, long double
 *     - complex types: float _Complex, double _Complex, long double _Complex
 *     - imaginary types: float _Imaginary, double _Imaginary,
 *                        long double _Imaginary
 * - enumerated types
 * - derived types
 *   - array types
 *   - structure types
 *   - union types
 *   - function types
 *   - pointer types
 *   - atomic types
 */

#include <stdio.h>

int main(void)
{
	char s[] = "C type";
	printf("%s\n", s);
	return 0;
}

/* https://en.cppreference.com/w/c/language/type */
