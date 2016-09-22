#include <stdio.h>

int main()
{
    char astring[256];

    printf("Please enter a string : ");
    fgets(astring, sizeof(astring), stdin);
    printf("You  entered a string : %s", astring);
    return 0;
}
