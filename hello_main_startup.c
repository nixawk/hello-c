#include <stdio.h>


__attribute__((constructor))
void
constructor(void)
{
    printf("main constructor\n");
}


__attribute__((destructor))
void
destructor(void)
{
    printf("main destructor\n");
}


int
main(void)
{
    printf("main function block\n");
    return 0;
}


// https://stackoverflow.com/questions/2053029/how-exactly-does-attribute-constructor-work