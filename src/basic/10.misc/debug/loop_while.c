long
loop_goto(long n)
{
    long result = 1;

loop:

    result *= n;
    n = n - 1;
    if (n > 1)
        goto loop;
    return result;
}


int
main()
{
    loop_goto(5);
    return 0;
}


/*

/ (fcn) sym.loop_goto 49
|   sym.loop_goto ();
|           ; var int local_18h @ rbp-0x18
|           ; var int local_8h @ rbp-0x8
|              ; CALL XREF from 0x5619dd4be69a (sym.main)
|           0x5619dd4be660      55             push rbp
|           0x5619dd4be661      4889e5         mov rbp, rsp
|           0x5619dd4be664      48897de8       mov qword [local_18h], rdi
|           0x5619dd4be668      48c745f80100.  mov qword [local_8h], 1
|              ; JMP XREF from 0x5619dd4be689 (sym.loop_goto)
|       .-> 0x5619dd4be670      488b45f8       mov rax, qword [local_8h]
|       |   0x5619dd4be674      480faf45e8     imul rax, qword [local_18h]
|       |   0x5619dd4be679      488945f8       mov qword [local_8h], rax
|       |   0x5619dd4be67d      48836de801     sub qword [local_18h], 1
|       |   0x5619dd4be682      48837de801     cmp qword [local_18h], 1 ; [0x1:8]=-1 ; 1
|      ,==< 0x5619dd4be687      7e02           jle 0x5619dd4be68b
|      |`=< 0x5619dd4be689      ebe5           jmp 0x5619dd4be670
|      `--> 0x5619dd4be68b      488b45f8       mov rax, qword [local_8h]
|           0x5619dd4be68f      5d             pop rbp
\           0x5619dd4be690      c3             ret

*/