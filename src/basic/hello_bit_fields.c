#include <stdio.h>

/*

In C, we can specify size (in bits) of structure and union members.
The idea is to use memory efficiently when we know that the value
of a field or group of fields will never exceed a limit or is withing
a small range.

*/

typedef struct date {
	/* d has value between 1 and 31, so 5 bits are sufficient */
	unsigned int d:5;

	/* m has value between 1 and 12, so 4 bits are sufficient */
	unsigned int m:4;
	unsigned int y;
} date_t;

int main(void)
{
	date_t dt = { 18, 8, 2018 };

	printf("Date size : %lu\n", sizeof(date_t));	/* IA64: 8 bytes */
	// printf("Date.d size: %lu\n", sizeof(dt.d));   /* error: invalid application of 'sizeof' to bit-field */
	printf("Date is   : %d/%d/%d\n", dt.d, dt.m, dt.y);

	return 0;
}

// http://www.geeksforgeeks.org/bit-fields-c/
// https://stackoverflow.com/questions/4129961/how-is-the-size-of-a-struct-with-bit-fields-determined-measured
