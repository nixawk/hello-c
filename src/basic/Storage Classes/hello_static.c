// Static Storage Class

// The static specifier gives the declared variable static storage class.
// Static variables can be used within function or file. Unlike global
// variables, static variables are not visible outside their function
// or file, but they mantain their values between calls. The static
// specifier has different effects upon local and global variables.

#include <stdio.h>

void storage_class_static()
{
	static int i = 0;

	printf("static int i = %d\n", i);
	i++;
}

int main(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		storage_class_static();
	}

	return 0;
}

/*

$ ./a.out
static int i = 0
static int i = 1
static int i = 2
static int i = 3

*/

/*

(gdb) disassemble storage_class_static 
Dump of assembler code for function storage_class_static:
   0x000000000000064a <+0>: push   rbp
   0x000000000000064b <+1>: mov    rbp,rsp
   0x000000000000064e <+4>: mov    eax,DWORD PTR [rip+0x2009c0]        # 0x201014 <i.2249>
   0x0000000000000654 <+10>:    mov    esi,eax
   0x0000000000000656 <+12>:    lea    rdi,[rip+0xd7]        # 0x734
   0x000000000000065d <+19>:    mov    eax,0x0
   0x0000000000000662 <+24>:    call   0x520 <printf@plt>
   0x0000000000000667 <+29>:    mov    eax,DWORD PTR [rip+0x2009a7]        # 0x201014 <i.2249>
   0x000000000000066d <+35>:    add    eax,0x1
   0x0000000000000670 <+38>:    mov    DWORD PTR [rip+0x20099e],eax        # 0x201014 <i.2249>
   0x0000000000000676 <+44>:    nop
   0x0000000000000677 <+45>:    pop    rbp
   0x0000000000000678 <+46>:    ret    
End of assembler dump.

*/

// http://cs-fundamentals.com/c-programming/storage-classes-in-c-and-storage-class-specifiers.php
