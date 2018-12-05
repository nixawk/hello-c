#include <stdio.h>

int
or(int x, int y)
{
    if (x > 0 || y > 0)
        printf("or success");
        return 0;
    return 1;
}


int
main()
{
    or(1, 2);
    return 0;
}


/*

/ (fcn) sym.or 50
|   sym.or ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x564228a4f6e0 (sym.main)
|           0x564228a4f6a0      55             push rbp
|           0x564228a4f6a1      4889e5         mov rbp, rsp
|           0x564228a4f6a4      4883ec10       sub rsp, 0x10
|           0x564228a4f6a8      897dfc         mov dword [local_4h], edi
|           0x564228a4f6ab      8975f8         mov dword [local_8h], esi
|           0x564228a4f6ae      837dfc00       cmp dword [local_4h], 0
|       ,=< 0x564228a4f6b2      7f06           jg 0x564228a4f6ba
|       |   0x564228a4f6b4      837df800       cmp dword [local_8h], 0
|      ,==< 0x564228a4f6b8      7e11           jle 0x564228a4f6cb
|      |`-> 0x564228a4f6ba      488d3db30000.  lea rdi, str.or_success ; 0x564228a4f774 ; "or success"
|      |    0x564228a4f6c1      b800000000     mov eax, 0
|      |    0x564228a4f6c6      e895feffff     call sym.imp.printf     ; int printf(const char *format)
|      `--> 0x564228a4f6cb      b800000000     mov eax, 0
|           0x564228a4f6d0      c9             leave
\           0x564228a4f6d1      c3             ret

*/