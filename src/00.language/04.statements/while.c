#include <stdio.h>

int main(void)
{
	int n;

	while (1) {
		printf("[*] enter a number: ");
		scanf("%d", &n);	/* try to input: 1 2 3 a */
		if (n >= 100)
			break;
		else
			printf("[%d], must be greater than 100\n", n);

	}
}

/* https://en.cppreference.com/w/c/language/while */
/* https://stackoverflow.com/questions/26583717/how-to-scanf-only-integer */
