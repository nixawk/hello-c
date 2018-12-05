#include <stdio.h>

int
lt(int x)
{
    if (x < 20)
        printf("x < 20");
        return 1;
    return 0;
}


int
main()
{
    lt(19);
    return 0;
}


/*

/ (fcn) sym.lt 41
|   sym.lt ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x564b84a356d2 (sym.main)
|           0x564b84a356a0      55             push rbp
|           0x564b84a356a1      4889e5         mov rbp, rsp
|           0x564b84a356a4      4883ec10       sub rsp, 0x10
|           0x564b84a356a8      897dfc         mov dword [local_4h], edi
|           0x564b84a356ab      837dfc13       cmp dword [local_4h], 0x13 ; [0x13:4]=-1 ; 19
|       ,=< 0x564b84a356af      7f11           jg 0x564b84a356c2       ; JMP if zf = 0
|       |   0x564b84a356b1      488d3dac0000.  lea rdi, str.x___20     ; 0x564b84a35764 ; "x < 20"
|       |   0x564b84a356b8      b800000000     mov eax, 0
|       |   0x564b84a356bd      e89efeffff     call sym.imp.printf     ; int printf(const char *format)
|       `-> 0x564b84a356c2      b801000000     mov eax, 1
|           0x564b84a356c7      c9             leave
\           0x564b84a356c8      c3             ret

*/