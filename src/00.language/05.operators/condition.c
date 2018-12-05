#include <stdio.h>

void condition(void)
{
	2 > 1 ? printf("Good\n") : printf("Bad\n");
}

int main(void)
{
	condition();
	return 0;
}

/* https://en.cppreference.com/w/c/language/expressions#Constants_and_literals */
