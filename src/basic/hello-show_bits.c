#include <stdio.h>

typedef unsigned char *byte_pointer;

void
show_bits(byte_pointer ptr, size_t len)
{
    size_t b1 = 0;
    size_t b0 = 0;
    size_t i;

    byte_pointer s = ptr;

    for (i=0; i < len; i++)
    {   
        for (int b = 0; b < 8; b++)
        {   
        ((*s << b) & 0x80) == 0x80 ? (b1 += 1) : (b0 += 1);
    }
    s++;
    }

    printf("[0] : %d, [1]: %d\n", b0, b1);
}

void
show_int(int x)
{
    show_bits((byte_pointer)&x, sizeof(int));
}

void
show_float(float x)
{
    show_bits((byte_pointer)&x, sizeof(float));
}

int
main(void)
{
    int x = 0xFF;
    show_int(x);

    float f = 12.34;
    show_float(f);

    byte_pointer ch = (byte_pointer)"helloworld";
    show_bits(ch, sizeof(ch));

    return 0;
}