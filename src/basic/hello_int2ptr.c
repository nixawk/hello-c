#include <stdio.h>
#include <stdint.h>

void
hello_int2ptr(void)
{
    uint32_t u32 = 0x11223344;
    uint8_t *p8;

    p8 = (uint8_t *)(&u32);
    printf(
        "[0]: %x, [1]: %x, [2]: %x, [3]: %x\n",
        p8[0], p8[1], p8[2], p8[3]
    );
}


int
main(void)
{
    hello_int2ptr();
    return 0;
}