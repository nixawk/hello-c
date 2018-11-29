
// Terminal Mode Data Types

// The entire collection of attributes of a terminal is stored in a structure
// of type struct termios. This structure is used with the functions tcgetattr
// and tcsetattr to read and set the attributes.

// A struct termios records all the I/O attributes of a terminal.
// The structure includes at least the following members:

    // tcflag_t c_iflag
    // A bit mask specifying flags for input modes.

    // tcflag_t c_oflag
    // A bit mask specifying flags for output modes.

    // tcflag_t c_cflag
    // A bit mask specifying flags for control modes.

    // tcflag_t c_lflag
    // A bit mask specifying flags for local modes.

    // cc_t c_cc[NCCS]
    // An array specifying which characters are associated with various control
    // functions.

// tcflag_t
// This is an unsigned integer type used to represent the various bit masks for
// terminal flags.

// cc_t
// This is an unsigned integer type used to represent the various terminal
// control functions.

// int NCCS
// The value of this macro is the number of elements in the c_cc array.

#include <termios.h>
#include <stdio.h>

void show_termios(void)
{
	struct termios tos;

	printf("c_iflag: %#lx\n", tos.c_iflag);
	printf("c_oflag: %#lx\n", tos.c_oflag);
	printf("c_cflag: %#lx\n", tos.c_cflag);
	printf("c_lflag: %#lx\n", tos.c_lflag);
}

int main(void)
{
	show_termios();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Mode-Data-Types.html#Mode-Data-Types
// https://www.gnu.org/software/libc/manual/html_node/Input-Modes.html#Input-Modes
// https://www.gnu.org/software/libc/manual/html_node/Output-Modes.html#Output-Modes
// https://www.gnu.org/software/libc/manual/html_node/Control-Modes.html#Control-Modes
// https://www.gnu.org/software/libc/manual/html_node/Local-Modes.html#Local-Modes
// http://man7.org/linux/man-pages/man3/termios.3.html
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/termios.h.html
// https://www.mkssoftware.com/docs/man5/struct_termios.5.asp
