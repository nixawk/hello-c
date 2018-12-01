long
do_while(long n)
{
    long result = 1;
    do {
        result *= n;
        n = n - 1;
    } while (n > 1);
    return result;
}


int
main()
{
    do_while(5);
    return 0;
}


/*

/ (fcn) sym.do_while 47
|   sym.do_while ();
|           ; var int local_18h @ rbp-0x18
|           ; var int local_8h @ rbp-0x8
|              ; CALL XREF from 0x55d1c6f1b698 (sym.main)
|           0x55d1c6f1b660      55             push rbp
|           0x55d1c6f1b661      4889e5         mov rbp, rsp
|           0x55d1c6f1b664      48897de8       mov qword [local_18h], rdi
|           0x55d1c6f1b668      48c745f80100.  mov qword [local_8h], 1
|       .-> 0x55d1c6f1b670      488b45f8       mov rax, qword [local_8h]
|       |   0x55d1c6f1b674      480faf45e8     imul rax, qword [local_18h]
|       |   0x55d1c6f1b679      488945f8       mov qword [local_8h], rax
|       |   0x55d1c6f1b67d      48836de801     sub qword [local_18h], 1
|       |   0x55d1c6f1b682      48837de801     cmp qword [local_18h], 1 ; [0x1:8]=-1 ; 1
|       `=< 0x55d1c6f1b687      7fe7           jg 0x55d1c6f1b670
|           0x55d1c6f1b689      488b45f8       mov rax, qword [local_8h]
|           0x55d1c6f1b68d      5d             pop rbp
\           0x55d1c6f1b68e      c3             ret

*/