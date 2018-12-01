#include <stdio.h>

int
ne(int x)
{
    if (x != 20)
        printf("x != 20");
        return 1;
    return 0;
}


int
main()
{
    ne(21);
    return 0;
}

/*

/ (fcn) sym.ne 41
|   sym.ne ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x55ce49fb66d2 (sym.main)
|           0x55ce49fb66a0      55             push rbp
|           0x55ce49fb66a1      4889e5         mov rbp, rsp
|           0x55ce49fb66a4      4883ec10       sub rsp, 0x10
|           0x55ce49fb66a8      897dfc         mov dword [local_4h], edi
|           0x55ce49fb66ab      837dfc14       cmp dword [local_4h], 0x14 ; [0x14:4]=-1 ; 20
|       ,=< 0x55ce49fb66af      7411           je 0x55ce49fb66c2       ; JMP if zf = 1
|       |   0x55ce49fb66b1      488d3dac0000.  lea rdi, str.x____20    ; 0x55ce49fb6764 ; "x != 20"
|       |   0x55ce49fb66b8      b800000000     mov eax, 0
|       |   0x55ce49fb66bd      e89efeffff     call sym.imp.printf     ; int printf(const char *format)
|       `-> 0x55ce49fb66c2      b801000000     mov eax, 1
|           0x55ce49fb66c7      c9             leave
\           0x55ce49fb66c8      c3             ret

*/