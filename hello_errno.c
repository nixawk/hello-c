#include <stdio.h>
#include <errno.h>

int main(void)
{
    fprintf(stderr, "Value of errno: %d\n", 1024);
    return 0;
}
