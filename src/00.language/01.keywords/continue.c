#include <stdio.h>

void keyword_continue(int i)
{
	for (; i < 15; i++) {
		if (i % 2 == 0)
			continue;
		printf("%d ", i);
	}
	printf("\n");
}

int main(void)
{ int x;
  scanf("%d',&x);
	keyword_continue(x);
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/continue */
