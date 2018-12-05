#include <stdio.h>

#define CONST "helloworld"

int
main()
{
    printf("%s\n", CONST);
    return 0;
}

/*

   0x00005555555546a0 <+0>: push   rbp
   0x00005555555546a1 <+1>: mov    rbp,rsp
=> 0x00005555555546a4 <+4>: lea    rdi,[rip+0x99]        # 0x555555554744
   0x00005555555546ab <+11>:    call   0x555555554560
   0x00005555555546b0 <+16>:    mov    eax,0x0
   0x00005555555546b5 <+21>:    pop    rbp
   0x00005555555546b6 <+22>:    ret 

*/

/*

code@lab:~/debug$ gcc -g3 -o constants_define_preprocessor constants_define_preprocessor.c 
code@lab:~/debug$ gdb constants_define_preprocessor 
Reading symbols from constants_define_preprocessor...done.

>>> info macro CONST
The symbol `CONST' has no definition as a C/C++ preprocessor macro
at <user-defined>:-1
>>> list main
2   
3   #define CONST "helloworld"
4   
5   int
6   main()
7   {
8       printf("%s\n", CONST);
9       return 0;
10  }

>>> info macro CONST
Defined at /home/code/debug/constants_define_preprocessor.c:3
#define CONST "helloworld"

*/

// https://stackoverflow.com/questions/10496195/gdb-macro-symbols-not-present-even-when-using-g3-or-ggdb3-or-gdwarf-4