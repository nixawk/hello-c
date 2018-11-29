#include <stdio.h>

int main(void)
{
	int num;
	printf("Please enter a number: ");
	scanf("%d", &num);

	if (num > 100)
		printf("%d is greater than 100\n", num);
	else if (num < 100)
		printf("%d is less than 100\n", num);
	else
		printf("%d is equal than 100\n", num);

	return 0;
}
