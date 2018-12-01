// $ gcc -g -o operator_mod operator_mod.c

int
mod(int x, int y)
{
    return x % y;
}


int
main()
{
    mod(7, 2);
    return 0;
}

/*

/ (fcn) sym.mod 21
|   sym.mod ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x559278baa683 (sym.main)
|           0x559278baa660      55             push rbp
|           0x559278baa661      4889e5         mov rbp, rsp
|           0x559278baa664      897dfc         mov dword [local_4h], edi # PARAMETER: int x
|           0x559278baa667      8975f8         mov dword [local_8h], esi # PARAMETER: int y
|           0x559278baa66a      8b45fc         mov eax, dword [local_4h]
|           0x559278baa66d      99             cdq
|           0x559278baa66e      f77df8         idiv dword [local_8h]     # eax = div(x, y)
|           0x559278baa671      89d0           mov eax, edx              # edx = mod(x, y)
|           0x559278baa673      5d             pop rbp
\           0x559278baa674      c3             ret

*/