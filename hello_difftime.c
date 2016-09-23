#include <time.h>
#include <unistd.h>  // sleep
#include <stdio.h>

/*
double difftime(time_t time1, time_t time2);

returns the different of seconds between time1 and time2 i.e (time1 - time2).

*/

int main()
{
    time_t start_t, end_t;

    time(&start_t);  // return a new time_t
    sleep(5);
    time(&end_t);    // return a new time_t

    printf("cost time : %f\n", difftime(end_t, start_t));
    return 0;
}
