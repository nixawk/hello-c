// Fizz Buzz - Write a program that prints the numbers from 1 to 1000.
//             But for multiples of three print "Fizz" instead of the number
//             and for multiples of five print "Buzz".
//             For numbers which are multiples of both three and five print "FizzBuzz"

#include <stdio.h>


void
FizzBuzz(int i)
{
    if (i % 15 == 0)
        printf("FizzBuzz ");
    else if (i % 3 == 0)
        printf("Fizz ");
    else if (i % 5 == 0)
        printf("Buzz ");
    else
        printf("%d ", i);
}

int
main(void)
{
    int i;

    for (i=1; i <= 100; i++)
    {
        FizzBuzz(i);
    }
    printf("\n");

    return 0;
}

// https://github.com/karan/Projects#Text
