/*
 * All system calls for perform I/O refer to open files using a file descriptor,
 * a (usually small) nonnegative integer. File descriptors are used to refer to
 * all types of open files, including pipes, FIFOs, sockets, terminals, devices
 * , and regular files. Each process has its own set of file descriptors.
 *
 * STDIN_FILENO  VS stdin
 * STDOUT_FILENO VS stdout
 * STDERR_FILENO VS stderr
 *
 * */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void open_usage(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY, S_IRWXU);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("[*] %s is opened\n", filename);

	if (close(fd) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}

}

int main(int argc, const char *argv[])
{
	if (argc < 2) {
		printf("[*] Usage: %s file1 file2 ... fileN\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++) {
		open_usage(argv[i]);
	}
	return 0;
}

/*
 * https://www.gnu.org/software/libc/manual/html_node/Opening-and-Closing-Files.html#Opening-and-Closing-Files
 * https://www.gnu.org/software/libc/manual/html_node/Access-Modes.html#Access-Modes
 * https://www.gnu.org/software/libc/manual/html_node/Open_002dtime-Flags.html#Open_002dtime-Flags
 * https://www.gnu.org/software/libc/manual/html_node/Operating-Modes.html#Operating-Modes
 * https://www.gnu.org/software/libc/manual/html_node/Getting-File-Status-Flags.html#Getting-File-Status-Flags
 * https://stackoverflow.com/questions/596306/using-the-open-system-call
 * https://stackoverflow.com/questions/2395465/create-a-file-in-linux-using-c
 * http://www.tutorialspoint.com/unix_system_calls/open.htm
 */
