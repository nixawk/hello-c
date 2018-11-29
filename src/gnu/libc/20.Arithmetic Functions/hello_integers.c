#include <stdint.h>
#include <stdio.h>

// The C language defines several integer data types: integer, short integer,
// long integer, and character, all in both signed and unsigned varieties.
// The GNU C compiler extends the language to contain long long integers.

// The C integer types were intended to allow code to be portable among
// machines with different inherent data size (word sizes), so each type
// may have different ranges on different machines. The problem with this
// is that a program often needs to be written for a particular range of
// integers, and sometimes must be written for a particular size of storage,
// regardless of what machine the program runs on.

// int8_t
// int16_t
// int32_t
// int64_t

// uint8_t
// uint16_t
// uint32_t
// uint64_t

void show_integers(void)
{
	int8_t i8b;
	int16_t i16b;

	printf("sizeof(int8_t) = %lu\n", sizeof(i8b));	// 8 bits = 1 byte
	printf("sizeof(int16_t) = %lu\n", sizeof(i16b));
}

int main(void)
{
	show_integers();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Integers.html#Integers
