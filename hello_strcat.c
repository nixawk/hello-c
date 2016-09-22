
#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "helloworld";
    char dest[256];
    char *strcat_pointer;

    memset(dest, '\x00', 256);
    strcat_pointer = strcat(dest, src);
    printf("destination string: %s\n", dest);
    printf("destination string: %s\n", strcat_pointer);
    return 0;
}
