#include <stdio.h>

int
loop_for()
{
    int i;
    for (i = 0; i < 5; i++)
        printf("i = %d\n", i);
    return 0;
}


int
main()
{
    loop_for();
    return 0;
}


/*

[0x7fb664d0bc20]> pdf @ sym.main 
            ;-- main:
/ (fcn) sym.main 21
|   sym.main ();
|              ; DATA XREF from 0x563061c6958d (entry0)
|           0x563061c696d8      55             push rbp
|           0x563061c696d9      4889e5         mov rbp, rsp
|           0x563061c696dc      b800000000     mov eax, 0
|           0x563061c696e1      e8baffffff     call sym.loop_for
|           0x563061c696e6      b800000000     mov eax, 0
|           0x563061c696eb      5d             pop rbp
\           0x563061c696ec      c3             ret

[0x7fb664d0bc20]> pdf @ sym.loop_for 
/ (fcn) sym.loop_for 17
|   sym.loop_for ();
|           ; var int local_4h @ rbp-0x4       ; x
|              ; CALL XREF from 0x563061c696e1 (sym.main)
|           0x563061c696a0      55             push rbp
|           0x563061c696a1      4889e5         mov rbp, rsp
|           0x563061c696a4      4883ec10       sub rsp, 0x10
|           0x563061c696a8      c745fc000000.  mov dword [local_4h], 0   ; int x = 0;
\       ,=< 0x563061c696af      eb1a           jmp 0x563061c696cb

[0x7fb664d0bc20]> pd 5 @ 0x563061c696cb 
        !      ; JMP XREF from 0x563061c696af (sym.loop_for)
        |   0x563061c696cb      837dfc04       cmp dword [rbp - 4], 4    ; if x == 4;
        `=< 0x563061c696cf      7ee0           jle 0x563061c696b1
            0x563061c696d1      b800000000     mov eax, 0
            0x563061c696d6      c9             leave
            0x563061c696d7      c3             ret

[0x7fb664d0bc20]> pd 12 @ 0x563061c696b1
        .-> 0x563061c696b1      8b45fc         mov eax, dword [rbp - 4]  ; eax = x;
        |   0x563061c696b4      89c6           mov esi, eax              ; 2nd printf parameter; x
        |   0x563061c696b6      488d3db70000.  lea rdi, str.i____d_n     ; 1st printf parameter; 0x563061c69774 ; "i = %d\n"
        |   0x563061c696bd      b800000000     mov eax, 0
        |   0x563061c696c2      e899feffff     call sym.imp.printf       ; int printf(edi, esi)
        |   0x563061c696c7      8345fc01       add dword [rbp - 4], 1    ; int x += 1;
        !      ; JMP XREF from 0x563061c696af (sym.loop_for)
        |   0x563061c696cb      837dfc04       cmp dword [rbp - 4], 4    ; if x == 4;
        `=< 0x563061c696cf      7ee0           jle 0x563061c696b1
            0x563061c696d1      b800000000     mov eax, 0
            0x563061c696d6      c9             leave
            0x563061c696d7      c3             ret
            ;-- main:

*/