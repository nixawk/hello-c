#include <stdio.h>

int main(void)
{
	printf("Current File: %s\n", __FILE__);
	printf("Current Date: %s\n", __DATE__);
	printf("Current Time: %s\n", __TIME__);
	printf("Line Number : %d\n", __LINE__);
	return 0;
}
