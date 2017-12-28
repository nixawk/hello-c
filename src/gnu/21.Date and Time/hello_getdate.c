// struct tm * getdate (const char *string)

// The formats recognized by getdate are the same as for strptime.

// getdate("10/1/87 4 PM");
// getdate("Friday");
// getdate("Friday September 18, 1987, 10:30:30");
// getdate("24,9,1986 10:30");
// getdate("at monday the 1st of december in 1986");
// getdate("run job at 3 PM, december 2nd");


#define _GNU_SOURCE
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
   struct tm *tmp;
   int j;

   for (j = 1; j < argc; j++) {
       tmp = getdate(argv[j]);

       if (tmp == NULL) {
           printf("Call %d failed; getdate_err = %d\n",
                  j, getdate_err);
           continue;
       }

       printf("Call %d (\"%s\") succeeded:\n", j, argv[j]);
       printf("    tm_sec   = %d\n", tmp->tm_sec);
       printf("    tm_min   = %d\n", tmp->tm_min);
       printf("    tm_hour  = %d\n", tmp->tm_hour);
       printf("    tm_mday  = %d\n", tmp->tm_mday);
       printf("    tm_mon   = %d\n", tmp->tm_mon);
       printf("    tm_year  = %d\n", tmp->tm_year);
       printf("    tm_wday  = %d\n", tmp->tm_wday);
       printf("    tm_yday  = %d\n", tmp->tm_yday);
       printf("    tm_isdst = %d\n", tmp->tm_isdst);
   }

   exit(EXIT_SUCCESS);
}


// https://www.gnu.org/software/libc/manual/html_node/General-Time-String-Parsing.html#General-Time-String-Parsing
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/getdate.html
// http://man7.org/linux/man-pages/man3/getdate.3.html