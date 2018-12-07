/*
 * A system call is a controlled entry point into the kernel, allowing a process
 * to request that the kernel perform some action on the process's behalf. The
 * kernel makes a range of services accessible to programs via the system call
 * application programming interface (API).
 *
 * 1. The application program makes a system call by invoking a wrapper function
 *    in the C library.
 *
 * 2. The wrapper function must make all of the system call arguments available
 *    to the system call trap-handling routine. These arguments are passed to
 *    the wrapper via the stack, but the kernel expects them in specific
 *    registers. The wrapper function copies the arguments to these registers.
 *
 * 3. Since all system calls enter the kernel in the same, the kernel needs some
 *    method of identifying the system call. To permit this, the wrapper
 *    function copies the system call number into a specific CPU register(%eax)
 *
 * 4. The wrapper function executes a trap machine instruction (int 0x80),
 *    which causes the processor to swith from user mode to kernel mode and
 *    execute code pointed to by location 0x80 (128 decimal) of the system's
 *    trap vector.
 *
 * 5. In response to the trap to location 0x80, the kernel invokes its
 *    system_call() routine (located in the assembler file arch/i386/entry.S)
 *    to handle the trap. This handler:
 *    	a) Saves register values onto the kernel stack
 *    	b) Checks the validity of the system call number
 *    	c) Invokes the appropiate system call service routine, which is found
 *    	   by using the system call number to index a table of all system call
 *    	   service routines (the kernel variable sys_call_table). If the system
 *    	   call service routine has any arguments, it first checks their
 *    	   validity; for example, it checks that addresses point to valid
 *    	   locations in user memory. Then the service routine performs the
 *    	   required task, which may involve modifying values at addresses
 *    	   specified in the given arguments and transferring data between
 *    	   user memory and kernel memory (e.g., I/O operations). Finally,
 *    	   the service routine returns a result status a to the system_call()
 *    	   routine.
 *    	d) Restores register values from the kernel stack and places the system
 *    	   call return value on the stack.
 *    	e) Returns to the wrapper function, simultaneously returning the
 *    	   processor to user mode.
 *
 * 6. If the return value of the system call service routine indicated an error,
 *    the wrapper function sets the global variable errno using this value. The
 *    wrapper function then returns the caller, providing an integer return
 *    value indicating the success or failure of the system call.
 * */

#define _GNU_SOURCE		/* See feature_test_macros(7) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>	/* For SYS_xxx definitions */

int main(void)
{
	long rv;

	rv = syscall(__NR_getpid);
	if (rv == -1) {
		perror("syscall");
		exit(EXIT_FAILURE);
	}
	printf("pid: %ld\n", rv);
	return 0;
}

/* http://man7.org/linux/man-pages/man2/syscalls.2.html */
/* https://syscalls.kernelgrok.com/ */
