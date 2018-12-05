#include <stdio.h>

int main(void)
{
	printf("hello, world\n");
	return 0;
}

// Compiling a source code file in C is a four-step process

    // 1. preprocessor  // gcc -E hello.c  // output: hello.i
    // 2. compiler      // gcc -S hello.c  // output: hello.s
    // 3. assembler     // gcc -c hello.c  // output: hello.o
    // 4. linker

// http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/compile.html
