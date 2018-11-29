
// According to the 1999 ISO C standard (C99), size_t is an
// unsigned integer type of at least 16 bit(see sections 7.17
// and 7.18.3).

// size_t is an unsigned data type defined by several C/C++
// standards, e.g. the C99 ISO/IEC 9899 standard, that is defined
// in [stddef.h]. It can be further imported by inclusion of
// stdlib.h as this file internally sub includes stddef.h.

// This type is used to represent the size of an object. Library
// functions that take or return sizes expect them to be of type
// or have the return type of size_t. Further, the most frequently
// used compiler-based operator sizeof should evaluate to a constant
// value that is compatible with size_t.

#include <stdlib.h>
#include <stdio.h>

void size_t_sizeof(void)
{
	printf("sizeof(size_t) = %ld\n", sizeof(size_t));
}

void size_t_signed_or_unsigned(void)
{
	size_t i = -1;

	printf("size_t i = -1; i = %zX\n", i);
}

int main(void)
{
	size_t_sizeof();
	size_t_signed_or_unsigned();

	return 0;
}

/* Tested on 64 bit platform

$ ./a.out
sizeof(size_t) = 8
size_t i = -1; i = FFFFFFFFFFFFFFFF

*/

// https://www.geeksforgeeks.org/size_t-data-type-c-language/
// https://stackoverflow.com/questions/2550774/what-is-size-t-in-c
// https://en.wikipedia.org/wiki/C_data_types#stddef.h
