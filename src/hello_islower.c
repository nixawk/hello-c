#include <ctype.h>
#include <stdio.h>

/*

int islower(int c);
int isupper(int c);

*/

int main(void)
{
    printf("%d\n", islower('a'));   // true
    printf("%d\n", islower('A'));   // false

    printf("%d\n", isupper('a'));   // false
    printf("%d\n", isupper('A'));   // true

    return 0;
}
