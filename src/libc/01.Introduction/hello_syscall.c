#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

/*

A system call is a controlled entry point into the kernel, allowing
a process to request that the kernel perform some action on the
process's behalf. The kernel makes a range of services accessible
to programs via the system call application programming interface
(API).

Before going into the details of how a system call works, we note
some general points:

- A system call changes the processor state from user mode to kernel
  mode, so that the CPU can access protected kernel memory.

- The set of system calls is fixed. Each system call is identified
  by a unique number. (This numbering scheme is not normally visible
  to programs, which identify system calls by name.)

- Each system call may have a set of arguments that specify information
  to be transfer from user space (i.e., the process's virtual address
  space) to kernel space and vice versa.

*/

void syscall_usage(void)
{
	const char *path = "/etc/passwd";
	int rval;

	// syscall(__NR_getuid) is equivalent to getuid()
	// printf("%ld\n", syscall(__NR_getuid));

	rval = syscall(__NR_access, path, R_OK);	// check read permissions
	if (rval == 0)
		printf("%s is readable !\n", path);
	else
		printf("%s is not readable !\n", path);
}

int main(void)
{
	syscall_usage();

	return 0;
}

/*

From a programming point of view, invoking a system call looks much
like calling a C function. However, behind the scenes, many steps
occur during the execution of a system call. To illustrate this,
we consider the steps in the order that they occur on a specific
hardware implementation, the x86-32. The steps are as follows:

1. The application program makes a system call by invoking a wrapper
   function in the C library.

2. The wrapper function must make all of the system call aguments
   available to the system call trap-handling routine (described shortly).
   These arguments are passed to the wrapper via the stack, but the
   kernel expects them in specific registers. The wrapper function
   copies the arguments to these registers.

3. Since all system calls enter the kernel in the same way, the kernel
   needs some method of identifying the system call. To permit this,
   the wrapper function copies the system call number into a specific
   CPU register (%eax).

4. The wrapper function executes a trap machine instruction (int 0x80),
   which causes the processor to switch from user mode to kernel mode
   and execute code pointed to by location 0x80 (128 decimal) of the
   system's trap vector.

5. Inresponse to the trap to location 0x80, the kernel invokes its
   system_call() routine (located in the assembler file arch/i386/entry.S)
   to handle the trap.

   a). Saves register values onto the kernel stack.
   b). Checks the validity of the system call number.
   c). Invokes the appropriate system call service routine, which is found
       by using the system call number to index a table of all system call
       service routines (the kernel variable sys_call_table). If the system
       call service routine has any arguments, it first checks their validity;
       for example, it checks that addresses point to valid locations in user
       memory. Then the service routine performs the required task, which
       may involve modifying values at addresses specified in the given
       arguments and transferring data between user memory and kernel
       memory. Finally, the servie routine returns a result status to the
       system_call() routine.
    d). Restores register values from the kernel stack and places the system
       call return value on the stack.
    e). Returns to the wrapper function, simultaneously returning the processor
       to user mode.

6. If the return value of the system call service routine indicated an error,
   the wrapper function sets the global variable errno using this value. The
   wrapper function then returns to the caller, providing an integer return
   value indicating the success or failure of the system call.

On linux, system call service routines follow a convention of returning a
nonnegative value to indicate success. In case of an error, the routine
returns a negative number, which is the negated value of one of the errno
constants. When a negative value is returned, the C library wrapper function
negates it (to make it positive), copies the result into errno, and returns
-1 as the function result of the wrapper to indicate an error to the calling
program.

*/

// http://man7.org/linux/man-pages/man2/syscall.2.html
// https://www.win.tue.nl/~aeb/linux/lk/lk-3.html
// https://github.com/torvalds/linux/tree/master/arch/x86/entry
// https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_32.tbl
