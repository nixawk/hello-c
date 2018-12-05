#include <stdio.h>

void keyword_static(void)
{
	static int i = 0;

	i++;
	printf("%d ", i);
}

int main(void)
{
	for (int i = 0; i < 5; i++) {
		keyword_static();	/* output: 1 2 3 4 5 */

	}
	printf("\n");
	return 0;
}
