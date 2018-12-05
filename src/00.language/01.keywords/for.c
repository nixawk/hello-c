#include <stdio.h>

void keyword_for(void)
{
	for(int i = 0; i < 3; i++) {
		printf("%d ", i);
	}
	printf("\n");
}

int main(void)
{
	keyword_for();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/for */
