#include <stdio.h>
#include <string.h>

int main(void)
{
    int ret;

    char astring1[] = "Helloworld1";
    char astring2[] = "Helloworld1";

    ret = strcmp(astring1, astring2); /* 0 - equal, -1 - not equal */

    if (0 == ret) {
        printf("astring1 is equal to astring2\n");
    }
    else {
        printf("astring1 is not equal to astring2\n");
    }

    return 0;
}
