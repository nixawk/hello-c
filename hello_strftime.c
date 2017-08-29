#include <time.h>
#include <stdio.h>


/*
size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr);

formats the time represented in the structure timeptr according to the formatting rules defined in format and stored into str.
*/

int main(void)
{
    time_t rawtime;
    struct tm *info;
    char buffer[256];

    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M %p", info);
    printf("Formatted date & time : |%s|\n", buffer);

    return 0;
}

// https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
