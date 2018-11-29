/*
A token passed to macro can be converted to a string literal by using # before it.
*/

#include <stdio.h>

#define tostr(a)  #a

int main(void)
{
	printf("%s\n", tostr(Hello World));
	return 0;
}
