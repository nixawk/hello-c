#include <stdio.h>

void
say_hello(msg)
    const char *msg;
{
    printf("hello, %s\n", msg);
}


int
main(argc, argv)
    int argc;
    const char *argv[];
{
    say_hello("pre-standard style");
    return 0;
}

// https://www.gnu.org/prep/standards/standards.html#Standard-C
// https://opensource.apple.com/source/Libc/Libc-167/gen.subproj/i386.subproj/strlen.c
