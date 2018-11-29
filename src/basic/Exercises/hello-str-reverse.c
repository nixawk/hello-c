// Reverse a String
// Enter a string and the program will reverse it and print it out

#include <stdio.h>

void my_swap(char *, char *);
size_t my_strlen(char *pstr);
void my_reverse(char *pstr);

/************************************************
 * swap char with each based on double pointers *
 ************************************************/
void my_swap(char *a, char *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/************************************************
 * get length of a str based on str pointer     *
 ************************************************/
size_t my_strlen(char *pstr)
{
	char *oldptr;

	for (oldptr = pstr; *oldptr;) {
		oldptr++;
	}

	return (size_t) (oldptr - pstr);
}

/************************************************
 * reverse a str based on str pointer           *
 ************************************************/
void my_reverse(char *pstr)
{
	size_t i, l;

	l = my_strlen(pstr);
	for (i = 0; i < (l / 2); i++) {
		my_swap(pstr + i, pstr + l - 1 - i);
	}
}

int main(void)
{
	// const char *rdstr = "hello, world-rd";  // readonly
	// char *rwstr = strdup(rdstr);            // writeable

	char rwstr[] = "hello, world";	// writeable

	printf("before rev : %s\n", rwstr);
	my_reverse(rwstr);
	printf("after  rev : %s\n", rwstr);

	return 0;
}

// https://github.com/karan/Projects#Text
