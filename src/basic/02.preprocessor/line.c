#include <stdio.h>

int main(void)
{
#line 100 "testfile"
	printf("%s:%d\n", __FILE__, __LINE__);
	return 0;
}

/* https://en.cppreference.com/w/c/preprocessor/line */
