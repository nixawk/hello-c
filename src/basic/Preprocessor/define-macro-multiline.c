/*
 The macros can be written in multiple lines using ‘\’. The last line doesn’t need to have ‘\’.
*/

#include <stdio.h>

#define PRINT(i, limit) while (i < limit) \
                        { \
                            printf("%d ", i); \
                            i++; \
                        }

int
main(void)
{
    int i = 0;
    PRINT(i, 5);
    return 0;
}