#include <ctype.h>
#include <stdio.h>

/*

int isgraph(int c)

The characters with graphical representations are all those characters that can be printed except for whitespace characters (like ' '), which is not considered as isgraph characters.

------

int isprint(int c)

A printable character is a character that is not a control character.

This is a set of Alphanumeric characters, Punctuation characters and Space characters.

------

int isspace(int c)

checks whether the passed character is white-space.

Standard white-space declartion for isspace() function.

' '   (0x20)   space (SPC)
'\t'  (0x09)   horizontial tab (TAB)
'\n'  (0x0a)   newline (LF)
'\v'  (0x0b)   vertical tab (VT)
'\f'  (0x0c)   feed(FF)
'\r'  (0x0d)   carriage return (CR)

*/

int main()
{
    printf("%d\n", isgraph('a'));    // true
    printf("%d\n", isgraph('&'));    // true
    printf("%d\n", isgraph(' '));    // false
    printf("%d\n", isgraph('\t'));   // false

    printf("%d\n", isprint('a'));    // true
    printf("%d\n", isprint('&'));    // true
    printf("%d\n", isprint(' '));    // true
    printf("%d\n", isprint('\t'));   // false
    return 0;
}
