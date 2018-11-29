#include <time.h>
#include <stdio.h>

// Function: time_t mktime (struct tm *brokentime)

// The mktime function converts a broken-down time structure to a simple time
// representation. It also normalizes the contents of the broken-down time
// structure, and fills in some components based on the values of the others.

// The mktime function ignores the specified contents of tm_wday, tm_yday,
// tm_gmtoff, and tm_zone members of the broken-down time structure. It uses
// the values of the other components to determine the calendar time; it's
// permissible for these components to have unnormalized values outside their
// normal ranges. The last thing that mktime does is adjust the components
// of the brokentime structure, including the members that were initially
// ignored.

// time_t timelocal (struct tm *brokentime)

// timelocal is functionally identical to mktime, but more mnermonically named.
// Note that it is the inverse of the localtime function.

// Protability note: mktime is essentially universally available. timelocal
// is rather than rare.

// Function: time_t timegm (struct tm *brokentime)

// timegm is functionally identical to mktime except it always takes the input
// values to be Coordinated Universal Time (UTC) regardless of any local time
// zone setting.

// Note that timegm is the inverse of gmtime.

// Portability note: mktime is essentially universally available. timegm is
// rather rare. For the most portable conversion from a UTC broken-down time
// to a simple time, set the TZ environment variable to UTC, call mktime,
// then set TZ back.

void mktime_usage(void)
{
	struct tm brokentime;
	time_t t;

	brokentime.tm_sec = 48;
	brokentime.tm_min = 15;
	brokentime.tm_hour = 4;
	brokentime.tm_mday = 27;
	brokentime.tm_year = 117;
	brokentime.tm_wday = 3;
	brokentime.tm_yday = 360;

	t = mktime(&brokentime);

	if (t != (time_t) (-1)) {
		printf("time_t t = %ld\n", t);
	}
}

int main(void)
{
	mktime_usage();
	return 0;
}

// $ ./a.out
// time_t t = 1485508548
// $ date -r 1485508548
// Fri Jan 27 04:15:48 EST 2017

// https://www.gnu.org/software/libc/manual/html_node/Broken_002ddown-Time.html#Broken_002ddown-Time
