/*
 * Every C program coded to run in a hosted execution environment contains the
 * definition (not the prototype) of a function called main, which is the 
 * designed start of the program.
 *
 */

/* gcc -e my_main 08.main_function.c */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("main function\n");
	return 0;
}

int my_main(void)
{
	printf("my_main function\n");
	exit(0);
}

/* https://en.cppreference.com/w/c/language/main_function */
