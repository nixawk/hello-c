#include <ctype.h>
#include <stdio.h>

/*
int iscntrl(int c)

This function checks whether the passed character is control character.

In ASCII, these characters have octal codes 000 through 037, and 177 (DEL).


*/

int main(void)
{
    printf("%d\n", iscntrl('\n'));   // true
    printf("%d\n", iscntrl('\t'));   // true
    printf("%d\n", iscntrl('\b'));   // true
    printf("%d\n", iscntrl('\a'));   // true
    printf("%d\n", iscntrl('\f'));   // true

    printf("%d\n", iscntrl('a'));    // false
    return 0;
}
