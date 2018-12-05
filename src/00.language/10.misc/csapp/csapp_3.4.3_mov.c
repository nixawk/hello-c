long exchange(long *xp, long y)
{
        long x = *xp;
        *xp = y;
        return x;
}

int main()
{
        return 0;
}


/*

/ (fcn) sym.exchange 40
|   sym.exchange ();
|           ; var int local_20h @ rbp-0x20
|           ; var int local_18h @ rbp-0x18
|           ; var int local_8h @ rbp-0x8
|           0x557becc87660      55             push rbp
|           0x557becc87661      4889e5         mov rbp, rsp
|           0x557becc87664      48897de8       mov qword [local_18h], rdi   ; int *x
|           0x557becc87668      488975e0       mov qword [local_20h], rsi   ; int y
|           0x557becc8766c      488b45e8       mov rax, qword [local_18h]
|           0x557becc87670      488b00         mov rax, qword [rax]
|           0x557becc87673      488945f8       mov qword [local_8h], rax    ; int z = *x
|           0x557becc87677      488b45e8       mov rax, qword [local_18h]
|           0x557becc8767b      488b55e0       mov rdx, qword [local_20h]
|           0x557becc8767f      488910         mov qword [rax], rdx         ; int *x = y
|           0x557becc87682      488b45f8       mov rax, qword [local_8h]
|           0x557becc87686      5d             pop rbp
\           0x557becc87687      c3             ret

*/