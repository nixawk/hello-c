#include<stdio.h> 

/*

Some data types like char , short int take less number of bytes than int,
these data types are automatically promoted to int or unsigned int when
an operation is performed on them. This is called integer promotion.

For example no arithmetic calculation happens on smaller types like char,
short and enum. They are first converted to int or unsigned int, and then
arithmetic is done on them. 

*/

void
integer_promotions(void)
{
    char c1 = 0xff, c2 = 0xdd, c3 = 0x01;
    char cX;

    // The expression (c1 * c2 + c3) seems to cause arithmetic overflow
    // because signed characters can have values only from -128 to 127
    // (in most of the C compilers), and the value of subexpression
    // (c1 * c2 = 0x23) is (0xdc23) which is greater than 128. But integer
    // promotion happens here in arithmetic done on char types and we get
    // the appropriate result without any overflow.

    cX = c1 * c2 + c3;

    printf("char: %x, %d, %c\n", cX, cX, cX);
}

int  main(void)
{
    integer_promotions();

    return 0;
}

// https://www.geeksforgeeks.org/integer-promotions-in-c/
