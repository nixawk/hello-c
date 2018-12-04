#include <stdio.h>

void keyword_else(void)
{
	int n;

	printf("[*] please enter a number: ");
	scanf("%d", &n);
	if (n >= 0)
		printf("%d > 0\n", n);
	else
		printf("%d < 0\n", n);
}

int main(void)
{
	keyword_else();
	return 0;
}
