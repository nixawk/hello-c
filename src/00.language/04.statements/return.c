/*
 * return expression;  (1)
 * return;             (2)
 *
 * 1) Evaluates the expression, terminates the current function and returns the
 *    result of the expression to the caller (the value returned becomes the
 *    value of the function call expression). Only valid if the function return
 *    type is not valid.
 * 2) Terminates the current function. Only valid if the function return type
 *    is void.
 * */

#include <stdio.h>

void foo(void)
{        printf("always here\n");    /*visites here*/
	return;                     /*returns to main*/
	printf("never here\n");    /* never comes here*/
}

int main(void)
{
	foo();                   /*funtion call*/
	return 0;
}

/* https://en.cppreference.com/w/c/language/return */
