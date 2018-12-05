#include <stdio.h>

int main(void)
{
	int n;

	printf("[*] please enter a number: ");
	scanf("%d", &n);

	if (n > 100)
		printf("%d is greater than 100\n", n);
	else if (n < 100)
		printf("%d is less than 100\n", n);
	else
		printf("%d is equal than 100\n", n);

	return 0;
}
