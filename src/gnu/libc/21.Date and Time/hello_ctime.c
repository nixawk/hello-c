#include <time.h>
#include <stdio.h>


// Function: char * ctime (const time_t *time)

// The ctime function is similar to asctime, except that you specify the
// calendar time argument as a time_t simple time value rather than in
// broken-down local time format. It is rquivalent to

    // asctime(localtime(time))

// Calling ctime also sets the current zone as if tzset were called.


// Function: char * ctime_r (const time_t *time, char *buffer)

// This function is similar to ctime, but places the result in the string
// pointed to by buffer. It is equivalent to (written using gcc extensions,
// see Statement Exprs in Porting and Using gcc):

    // ({ struct tm tm; asctime_r (localtime_r (time, &tm), buf); })

// If no error occurred the function returns a pointer to the string the
// result was written into, it returns buffer. Otherwise it returns NULL.


void
ctime_usage(void)
{
    const time_t time = 1514366148;
    char *ct;

    ct = ctime(&time);
    if (ct != NULL)
    {
        printf("%s\n", ct);
    }
}


int
main(void)
{
    ctime_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Formatting-Calendar-Time.html#Formatting-Calendar-Time