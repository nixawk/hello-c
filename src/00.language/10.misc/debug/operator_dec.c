// $ gcc -g -o operator_dec operator_dec.c

int
dec(int x)
{
    return x--;
}


int
main()
{
    dec(3);
    return 0;
}


/*

/ (fcn) sym.dec 18
|   sym.dec ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x5617938fa67b (sym.main)
|           0x5617938fa660      55             push rbp
|           0x5617938fa661      4889e5         mov rbp, rsp
|           0x5617938fa664      897dfc         mov dword [local_4h], edi    # PARAMETER: int x;
|           0x5617938fa667      8b45fc         mov eax, dword [local_4h]
|           0x5617938fa66a      8d50ff         lea edx, [rax - 1]           # !!! dr edx = 0x00000002
|           0x5617938fa66d      8955fc         mov dword [local_4h], edx
|           0x5617938fa670      5d             pop rbp
\           0x5617938fa671      c3             ret

*/