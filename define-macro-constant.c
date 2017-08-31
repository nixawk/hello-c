#include <stdio.h>

#define max 65535

int
main(void)
{
    printf("max is %d\n", max);
    return 0;
}


/*

code@lab:~/debug$ gcc -g3 -o define-constant define-constant.c 
code@lab:~/debug$ gdb -q ./define-constant 
Reading symbols from ./define-constant...done.
>>> list main
2   
3   #define max 65535
4   
5   int
6   main(void)
7   {
8       printf("max is %d\n", max);
9       return 0;
10  }
>>> macro list
>>> info macro max
Defined at /home/code/debug/define-constant.c:3
#define max 65535

*/