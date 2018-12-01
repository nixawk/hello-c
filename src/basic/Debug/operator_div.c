// $ gcc -g -o operator_div operator_div.c

int
div(int x, int y)
{
    return x / y;
}


int
main()
{
    div(4, 2);
    return 0;
}

/*

/ (fcn) sym.div 19
|   sym.div ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x55ae395246b1 (sym.main)
|           0x55ae39524690      55             push rbp
|           0x55ae39524691      4889e5         mov rbp, rsp
|           0x55ae39524694      897dfc         mov dword [local_4h], edi  # PARAMETER: int x
|           0x55ae39524697      8975f8         mov dword [local_8h], esi  # PARAMETER: int y
|           0x55ae3952469a      8b45fc         mov eax, dword [local_4h]
|           0x55ae3952469d      99             cdq                        # Only for eax, rax
|           0x55ae3952469e      f77df8         idiv dword [local_8h]
|           0x55ae395246a1      5d             pop rbp
\           0x55ae395246a2      c3             ret

*/