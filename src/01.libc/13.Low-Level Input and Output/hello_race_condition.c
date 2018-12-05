/*

Atomicity and Race Conditions

Atomicity is a concept that we'll encounter repeatedly when discussing
the operation of system calls. All system calls are executed atomatically.
By this, we mean that the kernel guarantees that all of the steps in a system
call are completed as a single operation, without being interrupted by ahother
process or thread.

Atomicity is essential to the successful completion of some operations.
In particular, it allows us to avoid race condtion (sometimes known as
race hazards). A race condtion is a sitution where the result produced
by two processes (or threads) operating on shared resources depends in
an unexpected way on the relative order in which the processes gain
access to the CPU(s).

*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define BUFSIZE 1024

void read_demo(const char *);
void write_demo(const char *, const char *);

void read_demo(const char *filename)
{
	char inbuf[BUFSIZE] = { 0 };
	ssize_t nr;
	int fd;

	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		printf("read_demo - failed to open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	nr = read(fd, inbuf, BUFSIZE);
	if (nr == -1) {
		printf("read_demo - failed to read %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("\n[*] [PID: %ld] - output: %s\n", (long)getpid(), inbuf);

	if (close(fd) == -1) {
		printf("read_demo - failed to close %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

void write_demo(const char *filename, const char *outbuf)
{
	int fd;
	ssize_t nw;

	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		printf("write_demo - failed to open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	nw = write(fd, outbuf, strlen(outbuf));
	if (nw == -1) {
		printf("write_demo - failed to write %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("\n[*] [PID: %ld] - input: %s\n", (long)getpid(), outbuf);

	if (close(fd) == -1) {
		printf("write_demo - failed to close %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, const char *argv[])
{
	int i;

	if (argc < 3) {
		printf("[*] Usage: %s <filename> <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	write_demo(argv[1], argv[2]);
	sleep(2);
	read_demo(argv[1]);

	exit(EXIT_SUCCESS);
}

/* r.sh

#!/bin/bash

rm -rf testfile
./a.out testfile AAAAAAAA &
./a.out testfile BBBBBBBB &

 */

/*

lab@lab-u64:~/Projects/c$ bash r.sh 
lab@lab-u64:~/Projects/c$ 
[*] [PID: 13215] - input: BBBBBBBB

[*] [PID: 13214] - input: AAAAAAAA

[*] [PID: 13215] - output: AAAAAAAA

[*] [PID: 13214] - output: AAAAAAAA

 */
