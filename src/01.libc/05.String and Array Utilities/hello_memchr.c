#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// void * memchr(const void *s, int c, size_t n);

// This function finds the first occurrence of the byte of c (converted into an unsigned char)
// in the initial size bytes of the object beginning at block.
// The return value is a pointer to the located byte, or a null pointer if no match was found.

void memchr_usage(void)
{
	const char s[] = "helloworld";
	int c = 'l';

	void *ptr = memchr(s, c, strlen(s));
	if (ptr == NULL) {
		printf("memchr() failed \n");
		exit(0);
	}

	printf("str pointer : %p, \ndst pointer : %p\n", s, ptr);
}

int main(void)
{
	memchr_usage();

	return 0;
}
