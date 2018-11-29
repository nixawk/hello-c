#include <stdio.h>

size_t _strlen(const char *str)
{
	const char *s;

	for (s = str; *s; s++) ;
	return (s - str);
}

int main(void)
{
	char s[] = "helloworld";

	printf("%d\n", _strlen(s));
	return 0;
}

// https://opensource.apple.com/source/Libc/Libc-167/gen.subproj/i386.subproj/strlen.c
