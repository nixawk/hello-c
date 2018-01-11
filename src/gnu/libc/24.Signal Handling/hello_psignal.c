#include <signal.h>

int
main(int argc, const char *argv[])
{
    psignal(SIGINT, "This is an interrupt signal message.");

    return 0;
}

/*

$ ./a.out 
This is an interrupt signal message.: Interrupt

*/