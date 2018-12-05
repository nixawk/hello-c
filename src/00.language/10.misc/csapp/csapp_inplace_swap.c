#include <stdio.h>

void inplace_swap(int *x, int *y)
{
        *y = *x ^ *y;  // *y1 = *x ^ *y
        *x = *x ^ *y;  // *x1 = *x ^ *y1 = *x ^ (*x ^ *y) = *x ^ *x ^ *y  = *y
        *y = *x ^ *y;  // *y2 = *x1 ^ *y1 = (*x ^ *y) ^  (*x ^ (*x ^ *y)) = *x
}

void reverse_array(int a[], int cnt)
{
        int first, last;

        for (first = 0, last = cnt - 1; first <= last; first++, last--)
        {
                inplace_swap(&a[first], &a[last]);
        }
}

void print_array(int a[], int cnt)
{
        for (int i = 0; i < cnt; i++)
                printf("%d ", a[i]);
}


int main()
{
        int a = 1;
        int b = 2;

        int i[] = {1, 2, 3, 4, 5};
        int len = sizeof(i) / sizeof(*i);

        inplace_swap(&a, &b);

        print_array(i, len);
        reverse_array(i, len);
        print_array(i, len);

        return 0;
}


/*

[0x5562d0b0370b]> pdf
            ;-- main:
/ (fcn) sym.main 83
|   sym.main ();
|           ; var int local_10h @ rbp-0x10
|           ; var int local_ch @ rbp-0xc
|           ; var int local_8h @ rbp-0x8
|              ; DATA XREF from 0x5562d0b035ad (entry0)
|           0x5562d0b0370b b    55             push rbp
|           0x5562d0b0370c      4889e5         mov rbp, rsp
|           0x5562d0b0370f      4883ec10       sub rsp, 0x10
|           0x5562d0b03713      64488b042528.  mov rax, qword fs:[0x28] ; [0x28:8]=-1 ; '(' ; 40
|           0x5562d0b0371c      488945f8       mov qword [local_8h], rax
|           0x5562d0b03720      31c0           xor eax, eax
|           0x5562d0b03722      c745f0010000.  mov dword [local_10h], 1
|           0x5562d0b03729      c745f4020000.  mov dword [local_ch], 2
|           ;-- rip:
|           0x5562d0b03730      488d55f4       lea rdx, [local_ch]
|           0x5562d0b03734      488d45f0       lea rax, [local_10h]
|           0x5562d0b03738      4889d6         mov rsi, rdx
|           0x5562d0b0373b      4889c7         mov rdi, rax
|           0x5562d0b0373e      e87dffffff     call sym.inplace_swap
|           0x5562d0b03743      b800000000     mov eax, 0
|           0x5562d0b03748      488b4df8       mov rcx, qword [local_8h]
|           0x5562d0b0374c      6448330c2528.  xor rcx, qword fs:[0x28]
|       ,=< 0x5562d0b03755      7405           je 0x5562d0b0375c
|       |   0x5562d0b03757      e824feffff     call sym.imp.__stack_chk_fail ; void __stack_chk_fail(void)
|       `-> 0x5562d0b0375c      c9             leave
\           0x5562d0b0375d      c3             ret

[0x5562d0b0370b]> pxw 8 @ rbp - 0x0c    ; int b =2;
0x7ffc1e3646f4  0x00000002 0x2905fd00                      .......)

[0x5562d0b0370b]> pxw 8 @ rbp - 0x10    ; int a = 1;
0x7ffc1e3646f0  0x00000001 0x00000002                      ........

[0x5562d0b0370b]> db 0x5562d0b03743
[0x5562d0b0370b]> dc
hit breakpoint at: 5562d0b03743

[0x5562d0b0370b]> pxw 8 @ rbp - 0x0c    ; int b = 1;
0x7ffc1e3646f4  0x00000001 0x2905fd00                      .......)

[0x5562d0b0370b]> pxw 8 @ rbp - 0x10    ; int a = 2;
0x7ffc1e3646f0  0x00000002 0x00000001                      ........


*/