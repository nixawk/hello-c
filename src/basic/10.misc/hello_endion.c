/*
Little and big endion are two ways of storing multibyte data-types (int, float, etc).
In little endian machines, last byte of binary representation of the multibyte data-type is stored first.
In big endian machines, first byte of binary representation of the multibyte data-type is stored first.

int x = 0x01234567;

0x100  0x101  0x102  0x103
-----------------------------
|  01  |  23  |  45  |  67  |   Big Endian
-----------------------------

0x100  0x101  0x102 0x103
-----------------------------
| 67 | 45 | 23 | 01 |   Little Endian
-----------------------------

*/

#include <stdio.h>

typedef int _bool;
// typedef unsigned char *byte_ptr;

union endian {
	char ch;
	unsigned int i;
};

_bool is_little_endian(void)
{
	// unsigned int x = 0x01234567;
	// return *((byte_ptr)&x) == 0x67; // return 0 or 1;

	union endian e;
	e.i = 0x01234567;
	return e.ch == 0x67;
}

int main(void)
{
	printf("%s\n", is_little_endian()? "little endian" : "big endian");
	return 0;
}
