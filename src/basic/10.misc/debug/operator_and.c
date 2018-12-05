#include <stdio.h>

int
add(int x, int y)
{
    if (x > 0 && y > 0)
        printf("and success");
        return 0
    return 1;
}


int
main()
{
    and(1, 2);
    return 0;
}

/*

/ (fcn) sym.and 50
|   sym.and ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x562bd1beb6e0 (sym.main)
|           0x562bd1beb6a0      55             push rbp
|           0x562bd1beb6a1      4889e5         mov rbp, rsp
|           0x562bd1beb6a4      4883ec10       sub rsp, 0x10
|           0x562bd1beb6a8      897dfc         mov dword [local_4h], edi
|           0x562bd1beb6ab      8975f8         mov dword [local_8h], esi
|           0x562bd1beb6ae      837dfc00       cmp dword [local_4h], 0
|       ,=< 0x562bd1beb6b2      7e17           jle 0x562bd1beb6cb
|       |   0x562bd1beb6b4      837df800       cmp dword [local_8h], 0
|      ,==< 0x562bd1beb6b8      7e11           jle 0x562bd1beb6cb
|      ||   0x562bd1beb6ba      488d3db30000.  lea rdi, str.and_success ; 0x562bd1beb774 ; "and success"
|      ||   0x562bd1beb6c1      b800000000     mov eax, 0
|      ||   0x562bd1beb6c6      e895feffff     call sym.imp.printf     ; int printf(const char *format)
|      ``-> 0x562bd1beb6cb      b800000000     mov eax, 0
|           0x562bd1beb6d0      c9             leave
\           0x562bd1beb6d1      c3             ret

*/