#include<stdio.h> 

/*

Some data types like char , short int take less number of bytes than int, these data types are automatically promoted to
int or unsigned int when an operation is performed on them. This is called integer promotion.

For example no arithmetic calculation happens on smaller types like char, short and enum.
They are first converted to int or unsigned int, and then arithmetic is done on them.
If an int can represent all values of the original type, the value is converted to an int.
Otherwise, it is converted to an unsigned int.

*/

int integer_promotions_char(void)
{
    char a = 0xfb;
    unsigned char b = 0xfb;
  
    if (a == b)
      printf("Same\n");
    else
      printf("Not Same\n");  // output here.
    return 0;
}

int integer_promotions_int(void)
{
   unsigned int x = -1;
   int y = ~0;

   if (x == y)
      printf("same\n");     // output here.
   else
      printf("not same\n");
   return 0;
}

int  main(void)
{
    integer_promotions_char();
    integer_promotions_int();
    return 0;
}