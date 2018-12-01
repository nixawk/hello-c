long arith(long x, long y, long z)
{
        long t1 = x ^ y;
        long t2 = z * 48;
        long t3 = t1 & 0x0F0F0F0F;
        long t4 = t2 - t3;
        return t4;
}

int main()
{
        return 0;
}



/*

/ (fcn) sym.arith 80
|   sym.arith ();
|           ; var int local_38h @ rbp-0x38
|           ; var int local_30h @ rbp-0x30
|           ; var int local_28h @ rbp-0x28
|           ; var int local_20h @ rbp-0x20
|           ; var int local_18h @ rbp-0x18
|           ; var int local_10h @ rbp-0x10
|           ; var int local_8h @ rbp-0x8
|           0x55bfd728e660      55             push rbp
|           0x55bfd728e661      4889e5         mov rbp, rsp
|           0x55bfd728e664      48897dd8       mov qword [local_28h], rdi  ; long x
|           0x55bfd728e668      488975d0       mov qword [local_30h], rsi  ; long y
|           0x55bfd728e66c      488955c8       mov qword [local_38h], rdx  ; long z
|           0x55bfd728e670      488b45d8       mov rax, qword [local_28h]  ; rax = x
|           0x55bfd728e674      483345d0       xor rax, qword [local_30h]  ; rax = x ^ y
|           0x55bfd728e678      488945e0       mov qword [local_20h], rax  ; var1 = rax = x ^ y
|           0x55bfd728e67c      488b55c8       mov rdx, qword [local_38h]  ; rdx = z
|           0x55bfd728e680      4889d0         mov rax, rdx                ; rax = rdx = z
|           0x55bfd728e683      4801c0         add rax, rax                ; rax = z + z
|           0x55bfd728e686      4801d0         add rax, rdx                ; rax = z + z + z
|           0x55bfd728e689      48c1e004       shl rax, 4                  ; rax = (3 * z) << 4 = 48 * z
|           0x55bfd728e68d      488945e8       mov qword [local_18h], rax  ; var2 = 48 * z
|           0x55bfd728e691      488b45e0       mov rax, qword [local_20h]  ; rax = var1
|           0x55bfd728e695      250f0f0f0f     and eax, 0xf0f0f0f          ; eax = var1 & 0xf0f0f0f
|           0x55bfd728e69a      488945f0       mov qword [local_10h], rax  ; var3 = var1 & 0xf0f0f0f
|           0x55bfd728e69e      488b45e8       mov rax, qword [local_18h]  ; rax = var2
|           0x55bfd728e6a2      482b45f0       sub rax, qword [local_10h]  ; rax = var2 - var3
|           0x55bfd728e6a6      488945f8       mov qword [local_8h], rax   ; var4 = rax = var2 - var3 = 48 * z - ((x ^ y) & 0xf0f0f0f)
|           0x55bfd728e6aa      488b45f8       mov rax, qword [local_8h]
|           0x55bfd728e6ae      5d             pop rbp
\           0x55bfd728e6af      c3             ret

*/