#include <string.h>
#include <stdio.h>

/*

char *strncat(char *dest, const char *src, size_t n);

appends the string pointed to by src to the end of the string pointed to by dest up to n characters long.

dest   - This is pointer to the destination array, which should contain a C string, and should be large enough to contain the concatenated resulting string which includes the additional null-character.
src    - This is the string to be appended.
n      - This is the maximum number of characters to be appended.

This function returns a pointer to the resulting string dest.

*/

int main(void)
{
	char dest[256];
	char src[256];
	char *pointer;

	strcpy(src, "This is source");
	strcpy(dest, "This is destination");

	pointer = strncat(dest, src, 15);
	printf("Final destination string : |%s|\n", dest);
	printf("Final destination string : |%s|\n", pointer);

	return 0;
}
