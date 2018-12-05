#include <stdio.h>

size_t x_strlen(const char *s)
{
	register const char *oldptr;

	for (oldptr = s; *s; s++) ;
	return (s - oldptr);
}

int main(int argc, const char *argv[])
{
	int i;

	if (argc < 2) {
		printf("[*] Usage: %s <str1> <str2> ...\n", argv[0]);
		return -1;
	}

	for (i = 1; i < argc; i++) {
		printf("%ld\n", x_strlen(argv[i]));
	}

	return 0;
}

// https://github.com/lattera/glibc/blob/master/string/strlen.c
// https://opensource.apple.com/source/Libc/Libc-167/gen.subproj/i386.subproj/strlen.c
// https://opensource.apple.com/source/Libc/Libc-997.1.1/string/FreeBSD/strlen.c
