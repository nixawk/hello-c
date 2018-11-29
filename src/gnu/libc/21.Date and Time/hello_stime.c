#include <time.h>
#include <stdio.h>

// Function: int stime(const time_t *newtime)

// stime sets the system clock, i.e., it tells the system that the current
// calendar time is newtime, where newtime is interpreted as described in
// the above definition of time_t.

// settimeofday is a newer function which sets the system clock to better
// than one second precision. settimeofday is generally a better choicce
// than stime.

// Only the superuser can set the system clock.

// If the function succeeds, the return value is zero. Otherwise, it is -1
// and errno is set accordingly:

// EPERM - The process is not superuser.

void stime_usage(void)
{
	time_t t;
	t = 0;
	stime(&t);
}

int main(void)
{
	stime_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Calendar-Time.html#Simple-Calendar-Time
// https://stackoverflow.com/questions/43298594/difference-between-time-and-stime
