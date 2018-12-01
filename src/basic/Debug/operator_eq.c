#include <stdio.h>

int
eq(int x)
{
    if (x == 20)
        printf("success\n");
        return 1;
    return 0;
}


int
main()
{
    eq(20);
    return 0;
}


/*

/ (fcn) sym.eq 36
|   sym.eq ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x56391ea876cd (sym.main)
|           0x56391ea876a0      55             push rbp
|           0x56391ea876a1      4889e5         mov rbp, rsp
|           0x56391ea876a4      4883ec10       sub rsp, 0x10
|           0x56391ea876a8      897dfc         mov dword [local_4h], edi  ; PARAMETER: int x
|           0x56391ea876ab      837dfc14       cmp dword [local_4h], 0x14 ; [0x14:4]=-1 ; 20
|       ,=< 0x56391ea876af      750c           jne 0x56391ea876bd      ; JMP if ~ZF
|       |   0x56391ea876b1      488d3dac0000.  lea rdi, str.success    ; 0x56391ea87764 ; "success"
|       |   0x56391ea876b8      e8a3feffff     call sym.imp.puts       ; int puts(const char *s)
|       `-> 0x56391ea876bd      b801000000     mov eax, 1
|           0x56391ea876c2      c9             leave
\           0x56391ea876c3      c3             ret

*/