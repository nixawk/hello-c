#include <stdio.h>

void keyword_else(void)      /* positive negative function*/
{
	int n;

	printf("[*] please enter a number: ");
	scanf("%d", &n);
	if (n >= 0)
		printf("%d > 0\n", n);
	        printf("%d is positive/n");
	else
		printf("%d < 0\n", n);
	         printf("%d is negative/n");
}

int main(void)
{
	keyword_else(); /*fuction call*/
	return 0;
}
