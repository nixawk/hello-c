#include <string.h>
#include <stdio.h>

/*
size_t strxfrm(char *dest, char *src, size_t n);

dest - This is the pointer to the destination array where the content is to be copied. It can be a null pointer if the argument for n is zero.
src  - This is the C string to be transformed into current locale
n    - The maximum number of characters to be copied to str1.

This function returns the length of the transformed string, not including the terminating null-character.

*/

int main(int argc, char const *argv[])
{
	char dest[20];
	char src[20];

	int len;

	strcpy(src, "helloworld");
	len = strxfrm(dest, src, 20);

	printf("Length of string |%s| is : |%d|", dest, len);
	return 0;
}
