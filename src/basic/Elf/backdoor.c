#include <stdio.h>

extern void backdoor(void);
extern void __attribute__ ((constructor)) constructor(void);
extern void __attribute__ ((destructor)) destructor(void);

void backdoor(void)
{
        printf("###################################\n"
                "##                               ##\n"
                "##       A SIMPLE BACKDOOR       ##\n"
                "##                               ##\n"
                "###################################\n");
}

void __attribute__ ((constructor)) constructor(void)
{
        backdoor();
}

void __attribute__ ((destructor)) destructor(void)
{
        ;
}
