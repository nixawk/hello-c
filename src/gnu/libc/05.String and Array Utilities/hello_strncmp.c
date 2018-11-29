#include <string.h>
#include <stdio.h>

/*

int strncmp(const char *str1, const char *str2, size_t n);

compares at most the first n bytes of str1 and str2.

str1  - This is the first string to be compared.
str2  - This is the second string to be compared.
n     - The maximum number of characters to be compared.

This function return values that are as follows:

if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2.

*/

int main(void)
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");

	ret = strncmp(str1, str2, 4);
	if (ret < 0) {
		printf("str1 is less than str2");
	} else if (ret > 0) {
		printf("str2 is less than str1");
	} else {
		printf("str1 is equal to str2");
	}

	return 0;
}
