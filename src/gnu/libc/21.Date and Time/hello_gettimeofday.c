#include <sys/time.h>
#include <stdio.h>

// The time_t data type used to represent simple times has a resolution of only
// second. Some application need more precision.

// So, the GNU C Library also contains functions which are capable of
// representing calendar times to a higher resolution than one second.
// The functions and the associated data types described in this section
// are declared in sys/time.h

// Data Type: struct timezone

// The struct timezone structure is used to hold minimal information about
// the local time zone. It has the following members:

// int tz_minuteswest
// This is the number of minutes west of UTC.

// int tz_dsttime
// If nonzero, Daylight Saving Time applies during some part of the year.

// The struct timezone type is obsolete and should never be used. Instead,
// use the facilities described in Time Zone Functions.

// Function: int gettimeofday (struct timeval *tp, struct timezone *tzp)

// The gettimeofday function returns the current calendar time as the elapsed
// time since the epoch in the struct timeval structure indicated by tp.

// The return value is 0 on success and -1 on failure. The following errno
// error condition is defined for this function:

    // ENOSYS - The operating system does not support getting time zone
    // information, and tzp is not a null pointer. GNU system do not support
    // using struct timezone to represent time zone information; that is
    // an obsolete feature of 4.3 BSD. Instead, use the facilities described
    // in Time Zone Functions.

// Data Type: struct timeval

// The struct timeval structure represents an elapsed time. It is declared in
// sys/time.h and has the following members.

    // time_t tv_sec
    // This represents the number of whole seconds of elapsed time.

    // long int tv_usec
    // This is the rest of elapsed time (a fraction of a second), represented
    // as the number of microseconds. It is always less than one million.

// int settimeofday (const struct timeval *tp, const struct timezone *tzp)
// int adjtime (const struct timeval *delta, struct timeval *olddelta)
// int adjtimex (struct timex *timex)

void gettimeofday_usage(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);

	printf("timeval.tv_sec  = %ld\n", t.tv_sec);
	printf("timeval.tv_usec = %d\n", t.tv_usec);
}

int main(void)
{
	gettimeofday_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/High_002dResolution-Calendar.html#High_002dResolution-Calendar
// http://man7.org/linux/man-pages/man2/gettimeofday.2.html
// https://www.gnu.org/software/libc/manual/html_node/Time-Zone-Functions.html#Time-Zone-Functions
// https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html
