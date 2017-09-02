#include<stdio.h>


int main(void)
{
    char c = 125;
    c = c + 10;         // c = 125 + 10 = 135 = 0x87;
    printf("%d", c);    // output: -121
    return 0;
}

/*

char, (default: signed char),

135 = 0x87 = 0b 1000 0111 = -(2 ** 7) + 4 + 2 + 1 = -121

*/