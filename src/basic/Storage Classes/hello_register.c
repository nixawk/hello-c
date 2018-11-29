// Register Storage Class

// The register specifier declares a variable of register storage class.
// Variables belonging to register storage class are local to the block
// which they are defined in, and get destroyed on exit from the block.
// A register declaration is equivalent to an auto declaration, but hints
// that the declared variable will be accessed frequently; therefore they
// are placed in CPU registers, not in memory. Only a few variables are
// actually placed into registers, and only certain types are eligible;
// the restrictions are implementation-dependent. However, if a variable
// is declared register, the unary & (address of) operator may not be
// applied to it, explicitly or implicitly. Register variables are also
// given no initial value by the compiler.

#include <stdio.h>

void storage_class_register(void)
{
	register int i = 10;

	// However, if a variable is declared register, the unary & (address of)
	// operator may not be applied to it,

	// int *p = &i;    // error: address of register variable requested

	for (i = 0; i < 5; i++) {
		printf("i = %d\n", i);
	}
}

int main(void)
{
	storage_class_register();
	return 0;
}

/*

(gdb) disassemble 
Dump of assembler code for function storage_class_register:
   0x000055555555464a <+0>: push   rbp
   0x000055555555464b <+1>: mov    rbp,rsp
   0x000055555555464e <+4>: push   rbx
   0x000055555555464f <+5>: sub    rsp,0x8
   0x0000555555554653 <+9>: mov    ebx,0xa        <-------------- register int i;
=> 0x0000555555554658 <+14>:    mov    ebx,0x0
   0x000055555555465d <+19>:    jmp    0x555555554675 <storage_class_register+43>
   0x000055555555465f <+21>:    mov    esi,ebx
   0x0000555555554661 <+23>:    lea    rdi,[rip+0xbc]        # 0x555555554724
   0x0000555555554668 <+30>:    mov    eax,0x0
   0x000055555555466d <+35>:    call   0x555555554520 <printf@plt>
   0x0000555555554672 <+40>:    add    ebx,0x1
   0x0000555555554675 <+43>:    cmp    ebx,0x4
   0x0000555555554678 <+46>:    jle    0x55555555465f <storage_class_register+21>
   0x000055555555467a <+48>:    nop
   0x000055555555467b <+49>:    add    rsp,0x8
   0x000055555555467f <+53>:    pop    rbx
   0x0000555555554680 <+54>:    pop    rbp
   0x0000555555554681 <+55>:    ret    
End of assembler dump.

*/

// http://cs-fundamentals.com/c-programming/storage-classes-in-c-and-storage-class-specifiers.php
