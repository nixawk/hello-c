#include <stdio.h>

void hello(const char *msg)
{
	printf("hello, %s\n", msg);
}

// gcc -Wall -shared -fpic -o library.so library.c
