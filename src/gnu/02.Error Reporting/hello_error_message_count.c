#include <error.h>
#include <stdio.h>

// unsigned int error_message_count

// The [error_message_count] variable is incremented whenever one of
// the functions [error] or [error_at_line] returns. The variable is
// global and shared by all threads.

/*

$ ./hello_error_message_count 
./hello_error_message_count: 1st err msg
./hello_error_message_count: 2nd err msg
err msg count: 2

*/

void
error_message_count_usage(void)
{
    error_at_line(0, 0, NULL, 0, "1st err msg");
    error_at_line(0, 0, NULL, 0, "2nd err msg");
    printf("err msg count: %d\n", error_message_count);
}


int
main(void)
{
    error_message_count_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Error-Reporting