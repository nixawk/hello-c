#include <stdio.h>


int
condition_operator(int x, int y)
{
    return x > y ? 1 : 0;
}


int
main()
{
    if (condition_operator(2, 1))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}


/*

/ (fcn) sym.condition_operator 24
|   sym.condition_operator ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x55e3cf63e6c6 (main)
|           0x55e3cf63e6a0      55             push rbp
|           0x55e3cf63e6a1      4889e5         mov rbp, rsp
|           0x55e3cf63e6a4      897dfc         mov dword [local_4h], edi
|           0x55e3cf63e6a7      8975f8         mov dword [local_8h], esi
|           0x55e3cf63e6aa      8b45fc         mov eax, dword [local_4h]
|           0x55e3cf63e6ad      3b45f8         cmp eax, dword [local_8h]
|           0x55e3cf63e6b0      0f9fc0         setg al
|           0x55e3cf63e6b3      0fb6c0         movzx eax, al
|           0x55e3cf63e6b6      5d             pop rbp
\           0x55e3cf63e6b7      c3             ret

*/