long scale(long x, long y, long z)
{
        long t = x + 4 * y + 12 * z;
        return t;
}


int main()
{
        return 0;
}


/*

/ (fcn) sym.scale 66
|   sym.scale ();
|           ; var int local_28h @ rbp-0x28
|           ; var int local_20h @ rbp-0x20
|           ; var int local_18h @ rbp-0x18
|           ; var int local_8h @ rbp-0x8
|           0x55d0339ce660      55             push rbp
|           0x55d0339ce661      4889e5         mov rbp, rsp
|           0x55d0339ce664      48897de8       mov qword [local_18h], rdi  ; long x
|           0x55d0339ce668      488975e0       mov qword [local_20h], rsi  ; long y
|           0x55d0339ce66c      488955d8       mov qword [local_28h], rdx  ; long z
|           0x55d0339ce670      488b45e0       mov rax, qword [local_20h]  ; rax = y
|           0x55d0339ce674      488d14850000.  lea rdx, [rax*4]            ; rdx = z = 4 * y
|           0x55d0339ce67c      488b45e8       mov rax, qword [local_18h]  ; rax = x
|           0x55d0339ce680      488d0c02       lea rcx, [rdx + rax]        ; rcx = x + z = x + 4 * y
|           0x55d0339ce684      488b55d8       mov rdx, qword [local_28h]  ; rdx = z
|           0x55d0339ce688      4889d0         mov rax, rdx                ; rax = rdx = z
|           0x55d0339ce68b      4801c0         add rax, rax                ; rax = z + z
|           0x55d0339ce68e      4801d0         add rax, rdx                ; rax = z + z + z
|           0x55d0339ce691      48c1e002       shl rax, 2                  ; rax = (3 * z) << 2
|           0x55d0339ce695      4801c8         add rax, rcx                ; rax = (3 * z) << 2 + x + 4 * y
|           0x55d0339ce698      488945f8       mov qword [local_8h], rax   ; var = (3 * z) << 2 + x + 4 * y # VAR = x + 4 * y + 12 * z ;
|           0x55d0339ce69c      488b45f8       mov rax, qword [local_8h]
|           0x55d0339ce6a0      5d             pop rbp
\           0x55d0339ce6a1      c3             ret

*/


/*

int
main()
{
    int x;
    int y = 12 * x;
    int z = (3 * x) << 2;  // y == z

    return 0;
}

/ (fcn) sym.main 41
|   sym.main ();
|           ; var int local_ch @ rbp-0xc
|           ; var int local_8h @ rbp-0x8
|           ; var int local_4h @ rbp-0x4
|              ; DATA XREF from 0x560a3cd3e54d (entry0)
|           0x560a3cd3e660      55             push rbp
|           0x560a3cd3e661      4889e5         mov rbp, rsp

            int y = 12 * x;
|           0x560a3cd3e664      8b55f4         mov edx, dword [local_ch]
|           0x560a3cd3e667      89d0           mov eax, edx
|           0x560a3cd3e669      01c0           add eax, eax
|           0x560a3cd3e66b      01d0           add eax, edx
|           0x560a3cd3e66d      c1e002         shl eax, 2
|           0x560a3cd3e670      8945f8         mov dword [local_8h], eax

            int z = (3 * x) << 2;
|           0x560a3cd3e673      8b55f4         mov edx, dword [local_ch]
|           0x560a3cd3e676      89d0           mov eax, edx
|           0x560a3cd3e678      01c0           add eax, eax
|           0x560a3cd3e67a      01d0           add eax, edx
|           0x560a3cd3e67c      c1e002         shl eax, 2
|           0x560a3cd3e67f      8945fc         mov dword [local_4h], eax

|           0x560a3cd3e682      b800000000     mov eax, 0
|           0x560a3cd3e687      5d             pop rbp
\           0x560a3cd3e688      c3             ret

*/

/*

    y = x << n;  // Equal to:  y = x * (2 ** n)

*/