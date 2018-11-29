#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

// Data Type: jmp_buf

// Objects of type [jmp_buf] hold the state information to be restored by a
// non-local exit. The contents of a [jmp_buf] identify a specific place to
// return to.

// int setjmp (jmp_buf state)

// When called normally, [setjmp] stores information about the execution
// states of the program in [state] and returns zero. If [longjmp] is
// later used to perform a non-local exit to this [state], [setjmp] returns
// a nonzero value.

// void longjmp (jmp_buf state, int value)

// This function restores current execution to the state saved in [state],
// and continues execution from the call to [setjmp] that established
// that return point. Returning from [setjmp] by means of [longjmp] returns
// a nonzero value.

jmp_buf state;

int x = 12;

void longjmp_usage(void)
{
	x = 34;
	longjmp(state, 1);
}

void setjmp_usage(void)
{
	if (setjmp(state) != 0) {
		printf("after longjmp\n");
		printf("x = %d\n", x);
		exit(0);
	}
	printf("x = %d\n", x);
	longjmp_usage();
}

int main(void)
{
	setjmp_usage();
	return 0;
}

/*

$ ./a.out
x = 12
after longjmp
x = 34

*/

// https://www.gnu.org/software/libc/manual/html_node/Non_002dLocal-Details.html
