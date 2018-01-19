#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void
print_current_time(void)
{
    time_t t;  /* time_t */
    char * s;  /* string */

    if ((t = time(NULL)) == (time_t) -1)
    {
        perror("time");
        exit(EXIT_FAILURE);
    }

    if ((s = ctime(&t)) == NULL)
    {
        perror("ctime");
        exit(EXIT_FAILURE);
    }

    printf("time() = %ld, \n\t %s\n", t, s);
}


int
main(void)
{
    print_current_time();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Formatting-Calendar-Time.html#Formatting-Calendar-Time