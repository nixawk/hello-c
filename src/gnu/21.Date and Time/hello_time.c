#include <time.h>
#include <stdio.h>

// Data Type: time_t

// This is the data type used to represent simple time. Sometimes, it also
// represents an elapsed time. When interpreted as a calendar time value,
// it represents the number of seconds elapsed since 00:00:00 on January 1,
// 1970, Coordinated Universal Time. POSIX requires that this count not
// include leap seconds, but on some systems this count includes leap
// seconds if you set TZ to certain values

// In the GNU C Library, time_t is equivalent to long int. In other
// systems, time_t might be either an integer or floating-point type.


void
show_time(void)
{
    time_t result;

    result = time(NULL);
    printf("current time: %lu\n", result);
}


int
main(void)
{
    show_time();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Simple-Calendar-Time.html#Simple-Calendar-Time