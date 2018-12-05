// gcc -g -o operator_mul operator_mul.c

int
mul(int x, int y)
{
    return x * y;
}


int
main()
{
    mul(2, 3);
    return 0;
}


/*

/ (fcn) sym.mul 19
|   sym.mul ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x55804656e681 (sym.main)
|           0x55804656e660      55             push rbp
|           0x55804656e661      4889e5         mov rbp, rsp
|           0x55804656e664      897dfc         mov dword [local_4h], edi  # PARAMETER: int x
|           0x55804656e667      8975f8         mov dword [local_8h], esi  # PARAMETER: int y
|           0x55804656e66a      8b45fc         mov eax, dword [local_4h]
|           0x55804656e66d      0faf45f8       imul eax, dword [local_8h]
|           0x55804656e671      5d             pop rbp
\           0x55804656e672      c3             ret

*/