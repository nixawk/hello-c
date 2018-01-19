#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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
time_and_gettimeofday(void)
{
    time_t tloc;
    struct timeval tv;

    if ((tloc = time(NULL)) == (time_t) -1)
    {
        perror("time");
        exit(EXIT_FAILURE);
    }

    if (gettimeofday(&tv, NULL) == -1)
    {
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }

    printf("time() = %ld\n", tloc);
    printf("gettimeofday() = %ld\n", tv.tv_sec);
}


int
main(void)
{
    time_and_gettimeofday();
    return 0;
}


// warning: implicit declaration of function ‘gettimeofday’ [-Wimplicit-function-declaration]

// https://www.gnu.org/software/libc/manual/html_node/Simple-Calendar-Time.html#Simple-Calendar-Time