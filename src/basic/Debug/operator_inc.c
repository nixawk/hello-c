// $ gcc -g -o operator_inc operator_inc.c

int
inc(int x)
{
    return x++;
}


int
main()
{
    inc(2);
    return 0;
}

/*

/ (fcn) sym.inc 18
|   sym.inc ();
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x561c6a7b967b (sym.main)
|           0x561c6a7b9660      55             push rbp
|           0x561c6a7b9661      4889e5         mov rbp, rsp
|           0x561c6a7b9664      897dfc         mov dword [local_4h], edi    # PARAMETER: int x;
|           0x561c6a7b9667      8b45fc         mov eax, dword [local_4h]
|           0x561c6a7b966a      8d5001         lea edx, [rax + 1]      ; 1  # !!! dr edx = 0x00000003
|           0x561c6a7b966d      8955fc         mov dword [local_4h], edx
|           0x561c6a7b9670      5d             pop rbp
\           0x561c6a7b9671      c3             ret

*/