#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 10; i++) {
		break;
		printf("i = %d\n", i);	/* nothing print */
	}
	return 0;
}

/* https://en.cppreference.com/w/c/language/break */
