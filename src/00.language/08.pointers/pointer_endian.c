#include <stdio.h>

int main(void)
{
	int n = 1234;

	if (*(char *)&n == 4)
		printf("big endian\n");
	else
		printf("small endian\n");

	return 0;
}

/* https://en.cppreference.com/w/c/language */
