#include <stdio.h>

int
ge(int x)
{
    if (x >= 20)
        printf("x >= 20");
        return 1;
    return 0;
}


int
main()
{
    ge(30);
    return 0;
}


/*

/ (fcn) sym.ge 41
|   sym.ge ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x55d944d916d2 (sym.main)
|           0x55d944d916a0      55             push rbp
|           0x55d944d916a1      4889e5         mov rbp, rsp
|           0x55d944d916a4      4883ec10       sub rsp, 0x10
|           0x55d944d916a8      897dfc         mov dword [local_4h], edi
|           0x55d944d916ab      837dfc13       cmp dword [local_4h], 0x13 ; [0x13:4]=-1 ; 19
|       ,=< 0x55d944d916af      7e11           jle 0x55d944d916c2
|       |   0x55d944d916b1      488d3dac0000.  lea rdi, str.x____20    ; 0x55d944d91764 ; "x >= 20"
|       |   0x55d944d916b8      b800000000     mov eax, 0
|       |   0x55d944d916bd      e89efeffff     call sym.imp.printf     ; int printf(const char *format)
|       `-> 0x55d944d916c2      b801000000     mov eax, 1
|           0x55d944d916c7      c9             leave
\           0x55d944d916c8      c3             ret

*/