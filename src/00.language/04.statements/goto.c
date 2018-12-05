#include <stdio.h>

void statement_goto(void)
{
	goto quit;
	printf("never here\n");

quit:
	printf("quit\n");
}

int main(void)
{
	statement_goto();
	return 0;
}
