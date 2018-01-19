#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*

struct tm {
    int tm_sec;   // Seconds (0-60)
    int tm_min;   // Minutes (0-59)
    int tm_hour;  // Hours (0-23)
    int tm_mday;  // Day of the month (1-31)
    int tm_mon;   // Month (0-11)
    int tm_year;  // Year since 1900
    int tm_wday;  // Day of the week (Sunday = 0)
    int tm_yday;  // Day in the year (0-365, 1 Jan = 0)
    int tm_isdst; // Daylight saving time flag
                  // > 0: DST is in effect.
                  // = 0: DST is not effect.
                  // < 0: DST information not available.
}

*/

void
time_ctime_gmtime(void)
{
    time_t t;       /* time()   return value */
    char *s;        /* ctime()  return value */
    struct tm *tm;  /* gmtime() return value */

    /* get time in seconds */

    if ((t = time(NULL)) == (time_t) -1)
    {
        perror("time");
        exit(EXIT_FAILURE);
    }

    /* convert a time value to a date and time string */

    if ((s = ctime(&t)) == NULL)
    {
        perror("ctime");
        exit(EXIT_FAILURE);
    }

    /* convert a time value to a broken-down UTC time */

    if ((tm = gmtime(&t)) == NULL)
    {
        perror("gmtime");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", s);
    printf("tm_sec = %d\n"
           "tm_min = %d\n"
           "tm_hour = %d\n"
           "tm_mday = %d\n"
           "tm_mon = %d\n"
           "tm_year = %d\n"
           "tm_wday = %d\n"
           "tm_yday = %d\n"
           "tm_isdst = %d\n",
           tm->tm_sec,
           tm->tm_min,
           tm->tm_hour,
           tm->tm_mday,
           tm->tm_mon,
           tm->tm_year,
           tm->tm_wday,
           tm->tm_yday,
           tm->tm_isdst);
}

int
main(void)
{
    time_ctime_gmtime();
    return 0;
}

/*

$ ./a.out
Thu Jan 18 23:02:52 2018

tm_sec = 52
tm_min = 2
tm_hour = 4
tm_mday = 19
tm_mon = 0
tm_year = 118
tm_wday = 5
tm_yday = 18
tm_isdst = 0

*/

// http://man7.org/linux/man-pages/man2/time.2.html
// http://man7.org/linux/man-pages/man3/ctime.3.html
// http://man7.org/linux/man-pages/man3/gmtime.3p.html