#include <time.h>
#include <stdio.h>

int main(void)
{
	// struct tm VS time_t
	// struct tm *t;
	time_t timer;

	time(&timer);
	// t = gmtime(&timer);
	timer = mktime(gmtime(&timer));	// return a timer pointer
	printf("time : %s\n", ctime(&timer));

	return 0;
}
