#include <stdlib.h>

// The easy way to run another program is to use the [system] function.
// This function does all the work of running a subprogram, but it doesn't
// give you much control over the details: you have to wait until the 
// subprogram terminates before you can do anything else.

// int system (const char *command)

// This function executes command as a shell command. In the GNU C Library,
// it always uses the default shell [sh] to run the command.
// In particular, it searches the directories in [PATH] to find programs to
// execute.

// If command is NULL, then a nonzero value if a shell is available, or 0
// if no shell is available.

// If a child process could not be created, or its status could not be
// retrieved, the return value is -1.

// If a shell could not be executed in the child process, then the return
// value is as though the child shell terminated by calling _exit(2) with
// the status 127.

// If all system calls succeed, then the return value is the termination
// status of the child shell used to execute command. (The termination
// status of a shell is the termination status of the last command it
// executes.)

void system_usage(void)
{
	const char *command = "whoami";
	system(command);
}

int main(void)
{
	system_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Running-a-Command.html#Running-a-Command
// https://linux.die.net/man/3/system
// http://man7.org/linux/man-pages/man3/system.3.html
// https://stackoverflow.com/questions/14222172/detecting-meaning-of-system-functions-return-value-in-linux
// http://www.unix.com/programming/32189-how-get-system-function-executed-cmd-return-value.html
