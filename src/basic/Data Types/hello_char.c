// char: The most basic data type in C. It stores a single character
// and requires a single byte of memory in almost all compilers.

    // char
    // signed char
    // unsigned char

#include <stdio.h>
#include <limits.h>

void
char_sizeof(void)
{
    printf("sizeof(char) = %lu byte(s), %d bit(s)\n", sizeof(char), CHAR_BIT);
}

void
char_readonly_or_writable(void)
{
    char *sr = "I'm readonly !";
    char sw[] = "I'm writable !";

    printf("sr = %p\n", sr);
    printf("sw = %p\n", sw);
}

void
char_signed_or_unsigned(void)
{
    char ch = 0x80;
    signed char sc = 0x80;
    unsigned char uc = 0x80; 

    if (ch == sc)
        printf("char == signed char\n");

    if (ch == uc)
        printf("char == unsigned char\n");
}

void
char_min_or_max(void)
{
    printf("CHAR_MIN  = %d\n", CHAR_MIN);
    printf("CHAR_MAX  = %d\n", CHAR_MAX);
    printf("UCHAR_MAX = %d\n", UCHAR_MAX);
}

int
main(void)
{
    char_sizeof();
    char_readonly_or_writable();
    char_signed_or_unsigned();
    char_min_or_max();

    return 0;
}

/*

$ ./a.out
sizeof(char) = 1 byte(s), 8 bit(s)
sr = 0x100428f23
sw = 0x7ffeef7d78e9
char == signed char
CHAR_MIN  = -128
CHAR_MAX  = 127
UCHAR_MAX = 255
*/

/*

Example:                       Allocation Type:     Read/Write:    Storage Location:   Memory Used (Bytes):
===========================================================================================================
const char* str = "Stack";     Static               Read-only      Code segment        6 (5 chars plus '\0')
char* str = "Stack";           Static               Read-only      Code segment        6 (5 chars plus '\0')
char* str = malloc(...);       Dynamic              Read-write     Heap                Amount passed to malloc
char str[] = "Stack";          Static               Read-write     Stack               6 (5 chars plus '\0')
char strGlobal[10] = "Global"; Static               Read-write     Data Segment (R/W)  10

*/

// https://www.cs.swarthmore.edu/~newhall/unixhelp/C_chars.html
// https://en.wikipedia.org/wiki/C_data_types
// https://stackoverflow.com/questions/25653034/the-difference-between-char-and-char
// https://www.tutorialspoint.com/c_standard_library/limits_h.htm
