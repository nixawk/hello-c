#include <time.h>
#include <stdio.h>

// Function: struct tm * localtime (const time_t *time)

// The localtime function converts the simple time pointed to by time to
// broken-down time representation, expressed relative to the user's
// specified time zone.

// The return value is a pointer to a static broken-down time structure,
// which might be overwritten by subsequent calls to ctime, gmttime, or
// localtime.

// The return value is the null pointer if time cannot be represented as
// a broken-down time; typically this is because the year cannot fit into
// an int.
// Calling localtime also sets the current time zone as if tzset were called.

void
localtime_usage(void)
{
    struct tm *tm;
    const time_t time = 1514366148;

    tm = localtime(&time);

    if (tm != NULL)
    {
        printf("tm->tm_sec = %d\n", tm->tm_sec);
        printf("tm->tm_min = %d\n", tm->tm_min);
        printf("tm->tm_hour = %d\n", tm->tm_hour);
        printf("tm->tm_mday = %d\n", tm->tm_mday);
        printf("tm->tm_mon = %d\n", tm->tm_mon);
        printf("tm->tm_year = %d\n", tm->tm_year);
        printf("tm->tm_wday = %d\n", tm->tm_wday);
        printf("tm->tm_yday = %d\n", tm->tm_yday);
        printf("tm->tm_isdst = %d\n", tm->tm_isdst);
        printf("tm->tm_gmtoff = %ld\n", tm->tm_gmtoff);
        printf("tm->tm_zone = %s\n", tm->tm_zone);  
    }
}


int
main(void)
{
    localtime_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Broken_002ddown-Time.html#Broken_002ddown-Time