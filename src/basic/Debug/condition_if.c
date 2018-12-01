#include <stdio.h>

int
condition_if(int x, int y)
{
    if (x > y)
        printf("x > y\n");
    else
        printf("x <= y\n");
    return 0;
}


int
main()
{
    condition_if(1, 2);
    return 0;
}


/*

/ (fcn) sym.condition_if 55
|   sym.condition_if ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x555b684ac6e5 (sym.main)
|           0x555b684ac6a0      55             push rbp
|           0x555b684ac6a1      4889e5         mov rbp, rsp
|           0x555b684ac6a4      4883ec10       sub rsp, 0x10
|           0x555b684ac6a8      897dfc         mov dword [local_4h], edi   ; PARAMETER: int x
|           0x555b684ac6ab      8975f8         mov dword [local_8h], esi   ; PARAMETER: int y
|           0x555b684ac6ae      8b45fc         mov eax, dword [local_4h]   ; eax = x;
|           0x555b684ac6b1      3b45f8         cmp eax, dword [local_8h]   ; cmp x, y
|       ,=< 0x555b684ac6b4      7e0e           jle 0x555b684ac6c4
|       |   0x555b684ac6b6      488d3dc70000.  lea rdi, str.x___y      ; 0x555b684ac784 ; "x > y"
|       |   0x555b684ac6bd      e89efeffff     call sym.imp.puts       ; int puts(const char *s)
|      ,==< 0x555b684ac6c2      eb0c           jmp 0x555b684ac6d0
|      |`-> 0x555b684ac6c4      488d3dbf0000.  lea rdi, str.x____y     ; 0x555b684ac78a ; "x <= y"
|      |    0x555b684ac6cb      e890feffff     call sym.imp.puts       ; int puts(const char *s)
|      |       ; JMP XREF from 0x555b684ac6c2 (sym.condition_if)
|      `--> 0x555b684ac6d0      b800000000     mov eax, 0
|           0x555b684ac6d5      c9             leave
\           0x555b684ac6d6      c3             ret

*/