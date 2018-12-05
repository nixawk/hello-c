/*
 * The break statement in C programming has the following two usages
 * - loop
 * - switch
 *
 * */

#include <stdio.h>

void keyword_break(void)
{
	int n;

	printf("[*] input a num: ");
	scanf("%d", &n);

	switch (n) {
	case 1:
		printf("good\n");
		break;
	case 0:
		printf("reversed\n");
		break;
	case -1:
		printf("bad\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}

int main(void)
{
	keyword_break();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword */
