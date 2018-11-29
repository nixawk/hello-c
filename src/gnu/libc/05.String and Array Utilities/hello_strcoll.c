#include <string.h>
#include <stdio.h>

/*

int strcoll(const char *s1, const char *s2);

compares string str1 to str2. The result is dependent on the LC_COLLATE setting of the location.

s1   - This is the first string to be compared.
s2   - This is the second string to be compared.

This function return values that are as follows:

if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2.

*/

int main(void)
{
	char s1[15];
	char s2[15];

	int ret;

	strcpy(s1, "abcdef");
	strcpy(s2, "ABCDEF");

	ret = strcoll(s1, s2);
	if (ret < 0) {
		printf("s1 is less than s2");
	} else if (ret > 0) {
		printf("s2 is less than s1");
	} else {
		printf("s1 is equal to s2");
	}

	return 0;
}
