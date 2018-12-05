#include <stdio.h>

void recurse(int count)
{
	if (count >= 10) {
		printf("Bingo !\n");
	} else {
		printf("id: %d\n", count);
		recurse(count + 1);
	}
}

int main(void)
{
	recurse(1);
	return 0;
}
