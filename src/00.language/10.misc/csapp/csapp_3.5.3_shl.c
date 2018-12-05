long shift_left4_rightn(long x, long n)
{
        x <<= 4;
        x >>= n;
        return x;
}


int main()
{
        return 0;
}


/*

/ (fcn) sym.shift_left4_rightn 33
|   sym.shift_left4_rightn ();
|           ; var int local_10h @ rbp-0x10
|           ; var int local_8h @ rbp-0x8
|           0x56031df7e660      55             push rbp
|           0x56031df7e661      4889e5         mov rbp, rsp
|           0x56031df7e664      48897df8       mov qword [local_8h], rdi   ; long x
|           0x56031df7e668      488975f0       mov qword [local_10h], rsi  ; long y
|           0x56031df7e66c      48c165f804     shl qword [local_8h], 4     ; x = (x << 4) = x * (2 ** 4)
|           0x56031df7e671      488b45f0       mov rax, qword [local_10h]  ; rax = y
|           0x56031df7e675      89c1           mov ecx, eax                ; ecx = eax = y
|           0x56031df7e677      48d37df8       sar qword [local_8h], cl    ; x = (x >> y)
|           0x56031df7e67b      488b45f8       mov rax, qword [local_8h]
|           0x56031df7e67f      5d             pop rbp
\           0x56031df7e680      c3             ret

*/