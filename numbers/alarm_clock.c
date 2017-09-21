// Program : Alarm Clock 
// Author  : Nixawk

#include <stdio.h>
#include <time.h>


#define BUFSIZE 512          /* buffer to save time string */

time_t get_ctime(void);    /* get current time */
time_t set_alarm(void);  /* set alert time */

void welcome(void);          /* alarm clock welcome message */
void alarm(time_t);          /* alarm clock */
void weakup(void);           /* alarm job */


time_t
get_ctime(void)
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Current local time and date: %s", asctime (timeinfo) );

    return mktime(timeinfo);
}


time_t
set_alarm(void)
{

    struct tm t;
    int mon, mday, year, hour, min, sec;

    welcome();

    /* convert a string into a (struct dm) */
    scanf("%d/%d/%d %d:%d:%d", &mon, &mday, &year, &hour, &min, &sec);
    t.tm_mon  = mon - 1;
    t.tm_mday = mday;
    t.tm_year = year - 1900;  /* read mktime details */
    t.tm_hour = hour;
    t.tm_min  = min;
    t.tm_sec  = sec;
    t.tm_isdst = -1;

    return mktime(&t);        /* call mktime: t->tm_wday will be set */
}


void
welcome(void)
{
    time_t now;
    char buf[BUFSIZE];

    printf("Welcome to The Alarm Clock\n");

    now = get_ctime();
    strftime(buf, BUFSIZE, "%m/%d/%Y %H:%M:%S", localtime(&now));
    printf("Alarm Clock, ex: [ %s ] > ", buf);
}


void
alarm(time_t e)
{
    double sec;
    time_t now;

    while (1)                   /* how to make alarm clock weak custom job */
    {
        now = get_ctime();      /* update current time */
        sec = difftime(now, e);
        if (sec > 0)
        {
            weakup();           /* custom weakup job here */
            break;
        }
    }

}


void
weakup(void)
{
    printf("Weakup to job\n");    /* alarm sound: \7 */
}


int
main(void)
{
    time_t e = set_alarm();
    alarm(e);
    return 0;
}


// References
// https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
// http://www.cplusplus.com/reference/ctime/time/
// http://www.cplusplus.com/reference/ctime/time_t/
// http://www.cplusplus.com/reference/ctime/tm/
// http://www.cplusplus.com/reference/ctime/asctime/
// https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-Time-String-Parsing.html
// http://www.cplusplus.com/reference/ctime/difftime/
// https://www.gnu.org/software/libc/manual/html_node/Time-Functions-Example.html