// gcc -g -o operator_sub operator_sub.c

int
sub(int x, int y)
{
    return x - y;
}


int
main()
{
    sub(2, 1);
    return 0;
}


/*

/ (fcn) sym.sub 18
|   sym.sub ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x563b83c6c680 (sym.main)
|           0x563b83c6c660      55             push rbp
|           0x563b83c6c661      4889e5         mov rbp, rsp
|           0x563b83c6c664      897dfc         mov dword [local_4h], edi  # PARAMETER: int x
|           0x563b83c6c667      8975f8         mov dword [local_8h], esi  # PARAMETER: int y
|           0x563b83c6c66a      8b45fc         mov eax, dword [local_4h]
|           0x563b83c6c66d      2b45f8         sub eax, dword [local_8h]
|           0x563b83c6c670      5d             pop rbp
\           0x563b83c6c671      c3             ret

*/