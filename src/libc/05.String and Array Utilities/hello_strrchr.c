#include <string.h>
#include <stdio.h>

/*
char *strrchr(const char *str, int c);

str - This is the C string.
c   - This is the character to be located. It is passed as its int promotion, but it is internally converted back to char.

This function returns a pointer to the last occurrence of character in str. If the value is not found, the function returns a null pointer.

*/

int main(int argc, char const *argv[])
{
	const char str[] = "helloworld";
	int c = 'l';
	char *pointer;

	pointer = strrchr(str, c);

	printf("str  pointer: %p\n", str);
	printf("char pointer: %p\n", pointer);
	return 0;
}
