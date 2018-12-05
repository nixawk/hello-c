#include <stdio.h>

int
gt(int x)
{
    if (x > 20)
        printf("x > 20");
        return 1;
    return 0;
}


int
main()
{
    gt(30);
    return 0;
}


/*

/ (fcn) sym.gt 41
|   sym.gt ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x561b6d68e6d2 (sym.main)
|           0x561b6d68e6a0      55             push rbp
|           0x561b6d68e6a1      4889e5         mov rbp, rsp
|           0x561b6d68e6a4      4883ec10       sub rsp, 0x10
|           0x561b6d68e6a8      897dfc         mov dword [local_4h], edi
|           0x561b6d68e6ab      837dfc14       cmp dword [local_4h], 0x14 ; [0x14:4]=-1 ; 20
|       ,=< 0x561b6d68e6af      7e11           jle 0x561b6d68e6c2      ; JMP if zf = 1
|       |   0x561b6d68e6b1      488d3dac0000.  lea rdi, str.x___20     ; 0x561b6d68e764 ; "x > 20"
|       |   0x561b6d68e6b8      b800000000     mov eax, 0
|       |   0x561b6d68e6bd      e89efeffff     call sym.imp.printf     ; int printf(const char *format)
|       `-> 0x561b6d68e6c2      b801000000     mov eax, 1
|           0x561b6d68e6c7      c9             leave
\           0x561b6d68e6c8      c3             ret

*/