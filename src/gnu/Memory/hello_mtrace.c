#include <mcheck.h>
#include <stdlib.h>


// void mtrace (void)
// void muntrace (void)

// When the [mtrace] function is called it looks for an environment variable named
// [MALLOC_TRACE]. This variable is supported to contain a valid file name. The 
// user must have write access. If the file already exists it is truncated. If 
// the environment variable is not set or it does not name a valid file which 
// can be opened for writing nothing is done. The behavior of malloc etc. is 
// not changed. 

// The muntrace function can be called after mtrace was used to enable tracing 
// the malloc calls. If no (successful) call of mtrace was made muntrace does nothing.

// Otherwise it deinstalls the handlers for malloc, realloc, and free and then 
// closes the protocol file. No calls are protocolled anymore and the program runs 
// again at full speed.


#define SIZE 256


void
mtrace_usage(void)
{
    char *buf;

    mtrace();   /* enable tracing */

    buf = (char *)malloc(SIZE);
    free(buf);

    muntrace(); /* disable tracing */
}


int
main(void)
{
    mtrace_usage();
    return 0;
}


/*

$ MALLOC_TRACE=/tmp/malloc_trace.log ./test 
$ cat malloc_trace.log 
= Start
@ ./test:[0x563418c1a787] + 0x563419f35450 0x100
@ ./test:[0x563418c1a797] - 0x563419f35450
= End


*/

// https://www.gnu.org/software/libc/manual/html_node/Tracing-malloc.html#Tracing-malloc