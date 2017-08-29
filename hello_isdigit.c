#include <ctype.h>
#include <stdio.h>


// int isdigit(int c);
// int isxdigit(int c);

int main(void)
{
    printf("%d\n", isdigit('0'));  // true
    printf("%d\n", isdigit(0));    // false

    char c1[] = "0x0A";

    printf("%d\n", isxdigit(c1[0])); // true
    printf("%d\n", isxdigit('a'));   // true
    printf("%d\n", isxdigit('&'));   // false
    return 0;
}
