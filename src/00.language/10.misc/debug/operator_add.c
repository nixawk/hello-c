// $ gcc -g -o operator_add operator_add.c

int
add(int x, int y)
{
    return x + y;
}

int
main()
{
    add(1, 2);
    return 0;
}


/*

[0x7ff9c70ebc20]> pdf @ sym.add
/ (fcn) sym.add 20
|   sym.add ();
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; CALL XREF from 0x563853f82682 (sym.main)
|           0x563853f82660      55             push rbp
|           0x563853f82661      4889e5         mov rbp, rsp
|           0x563853f82664      897dfc         mov dword [local_4h], edi  # parameter: int x
|           0x563853f82667      8975f8         mov dword [local_8h], esi  # parameter: int y
|           0x563853f8266a      8b55fc         mov edx, dword [local_4h]
|           0x563853f8266d      8b45f8         mov eax, dword [local_8h]
|           0x563853f82670      01d0           add eax, edx
|           0x563853f82672      5d             pop rbp
\           0x563853f82673      c3             ret

*/