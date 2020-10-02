#include <stdio.h>
void recurse(int); //funtion prototype
void recurse(int count) //function defenition
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
	recurse(1); //function call or recursive call as it is recursive function
	return 0;
}
