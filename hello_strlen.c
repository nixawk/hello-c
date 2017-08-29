#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "helloworld";
    int length;

    length = strlen(src);

    printf("string length : %d\n", length);
    return 0;
}
