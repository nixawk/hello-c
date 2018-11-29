#include <stdio.h>

// Deprecated function: char * gets (char *s)

// The function gets reads characters from the stream stdin up to the next
// newline character, and stores them in the string s. The newline character
// is discarded (note that this differs from the behavior of fgets, which
// copies the newline character into the string). If gets encounters a read
// error or end-of-file, it returns a null pointer; otherwise it returns s.

// The gets function is very dangerous because it provides no protection
// against overflowing the string s. The GNU C Library includes it for
// compatibility only. You should always use fgets or getline instead.
// To remind you of this, the linker (if using GNU ld) will issue a warning
// whenever you use gets.

void gets_usage(void)
{
	char buf_overflow[32];
	puts(gets(buf_overflow));
}

int main(void)
{
	gets_usage();
	return 0;
}

/*

$ ./a.out
warning: this program uses gets(), which is unsafe.
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
[1]    1450 abort      ./a.out

*/

// http://man7.org/linux/man-pages/man3/gets.3.html
// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html#Line-Input
