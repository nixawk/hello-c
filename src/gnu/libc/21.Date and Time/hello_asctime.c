#include <time.h>
#include <stdio.h>

// Function: char * asctime (const struct tm *brokentime)

// The asctime function converts the broken-down time value that brokentime
// points to into a string in a standard format:

// "Tue May 21 13:46:22 1991\n"

// The return value points to a statically allocated string, which might be
// overwritten by subsequent calls to asctime or ctime. (But no other library
// function overwrites the contents of this string.)


// Function: char * asctime_r (const struct tm *brokentime, char *buffer)

// This function is similar to asctime but instead of placing the result
// in a static buffer it writes the string in the buffer pointed to by the
// parameter buffer. This buffer should have room for at least 26 bytes,
// including the terminating null. If no error occurred the function returns
// a pointer to the string the result was written into, it returns buffer.
// Otherwise it returns NULL.

void
asctime_usage(void)
{
    struct tm *tm;
    char *timestr;
    const time_t time = 1514366148;

    tm = localtime(&time);
    timestr = asctime(tm);

    if (timestr != NULL)
    {
        printf("%s\n", timestr);
    }
}


int
main(void)
{
    asctime_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Formatting-Calendar-Time.html#Formatting-Calendar-Time