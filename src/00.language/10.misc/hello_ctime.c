#include <time.h>
#include <stdio.h>

/*

char *ctime(const time_t *timer);

return a string representing the localtime based on the argument timer.
The returned string has the following format: Www Mmm dd hh:mm:ss yyyy,
where Www is the weekday,
Mmm the month in letters,
dd the day of the month,
hh:mm:ss the time, and yyyy the year.
*/

int main(void)
{
	time_t *timer;
	time_t rtimer;

	rtimer = time(timer);

	printf("Current time = %s", ctime(&rtimer));
	printf("Current time = %s", ctime(timer));

	printf("rtimer pointer : %p\n", &rtimer);
	printf("timer pointer  : %p\n", timer);
	return 0;
}
