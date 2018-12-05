#include <stdio.h>

void keyword_goto(void)
{
	goto quit;
	printf("never here\n");

quit:
	printf("quit\n");
}

int main(void)
{
	keyword_goto();
	return 0;
}
