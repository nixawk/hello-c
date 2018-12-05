/*
extern: extern simply tells us that the variable is defined elsewhere and not
within the same block where it is used. Basically, the value is assigned to it
in a different block and this can be overwritten/changed in a different block
as well.

The main purpose of using extern variables is that they can be accessed between
different files which are part of a large program.
*/

#include <stdio.h>

extern void keyword_extern(char *);

void keyword_extern(char *s)
{
	printf("hello %s\n", s);
}

int main(void)
{
	keyword_extern("keyword extern");
	return 0;
}

/*
If "void keyword_extern" in multi c files, gcc gains an error as follow:

    /tmp/ccZuMDlf.o: In function `keyword_extern':
    extern_func.c:(.text+0x0): multiple definition of `keyword_extern'
    /tmp/ccpXQPU1.o:extern_main.c:(.text+0x0): first defined here

*/
