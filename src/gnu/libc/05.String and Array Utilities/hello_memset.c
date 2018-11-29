#include <string.h>
#include <stdio.h>

/*

void *memset(void *str, int c, size_t n);

copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.

str  - This is a pointer to the block of memory to fill.
c    - This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
n    - This is the number of bytes to be set to the value.

This function returns a pointer to the memory area str.

*/

int main(void)
{
	char aStr[] = "helloworld";

	printf("string: %s\n", aStr);
	memset(aStr, 0, sizeof(aStr));

	return 0;
}
