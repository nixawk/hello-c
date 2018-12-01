#include <stdio.h>

int
le(int x)
{
    if (x <= 20)
        printf("x <= 20");
        return 1;
    return 0;
}


int
main()
{
    le(19);
    return 0;
}


/*

/ (fcn) sym.le 41
|   sym.le ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x55c11a8cb6d2 (sym.main)
|           0x55c11a8cb6a0      55             push rbp
|           0x55c11a8cb6a1      4889e5         mov rbp, rsp
|           0x55c11a8cb6a4      4883ec10       sub rsp, 0x10
|           0x55c11a8cb6a8      897dfc         mov dword [local_4h], edi
|           0x55c11a8cb6ab      837dfc14       cmp dword [local_4h], 0x14 ; [0x14:4]=-1 ; 20
|       ,=< 0x55c11a8cb6af      7f11           jg 0x55c11a8cb6c2
|       |   0x55c11a8cb6b1      488d3dac0000.  lea rdi, str.x____20    ; 0x55c11a8cb764 ; "x <= 20"
|       |   0x55c11a8cb6b8      b800000000     mov eax, 0
|       |   0x55c11a8cb6bd      e89efeffff     call sym.imp.printf     ; int printf(const char *format)
|       `-> 0x55c11a8cb6c2      b801000000     mov eax, 1
|           0x55c11a8cb6c7      c9             leave
\           0x55c11a8cb6c8      c3             ret

*/