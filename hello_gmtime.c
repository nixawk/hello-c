#include <time.h>
#include <stdio.h>

int main(void)
{
    struct tm *t;
    time_t timer;

    /*
    t = gmtime(&timer);
    printf("sec:   %d\n", t->tm_sec);
    printf("min:   %d\n", t->tm_min);
    printf("hour:  %d\n", t->tm_hour);
    printf("mday:  %d\n", t->tm_mday);
    printf("mon:   %d\n", t->tm_mon);
    printf("year:  %d\n", t->tm_year);
    printf("wday:  %d\n", t->tm_wday);
    printf("yday:  %d\n", t->tm_yday);
    printf("isdst: %d\n", t->tm_isdst);
    */

    printf("%s\n", asctime(gmtime(&timer)));
    return 0;
}
