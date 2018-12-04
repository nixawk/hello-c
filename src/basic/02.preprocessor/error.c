#include <stdio.h>

int main(void)
{
#ifndef DEBUG
#error "-DDEBUG is a must"
#endif
	return 0;
}

/* https://en.cppreference.com/w/c/preprocessor/error */
