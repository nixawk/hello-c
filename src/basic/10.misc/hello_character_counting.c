#include <stdio.h>

int main(void)
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;

	/*
	   ++, which means increment by one. You could instead write nc = nc + 1,
	   but ++nc is more concise and often more efficient.

	   What's the difference between ++nc and nc++ ?
	 */

	printf("%ld\n", nc);

	return 0;
}

/*
$ echo AAAAAAA | ./a.out
8
*/
