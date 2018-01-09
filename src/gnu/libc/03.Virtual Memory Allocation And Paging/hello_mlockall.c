#include <sys/mman.h>


    // int mlockall (int flags)

// mlockall locks all the pages in a process' virtual memory address space,
// and/or any that are added to it in the future. This includes the pages
// of the code, data and stack segment, as well as shared libraries, user
// space kernel data, shared memory, and memory mapped files.

// flags is a string of single bit flags represented by the following macros.
// They tell mlockall which of its functions you want.

    // MCL_CURRENT

// Lock all pages which currently exist in the calling process' virtual 
// address sapce 

    // MCL_FUTURE

// Set a mode such that any pages added to the process' virtual space in
// the future will be locked from birth. This mode does not affect future
// spaces owned by the same process so exec, which replaces a process'
// address space, wipes out them.


    // int munlockall (void)

// munlockall unlocks every page in the calling process' virtual address space
// and turn off MCL_FUTURE future locking mode.

// The return value is zero if the function succeeds. Otherwise, it is -1 and
// errno is set accordingly. The only way this function can fail is for generic
// reasons that all functions and systems calls can fail, so there are no
// specific errno values.


void
mlockall_usage(void)
{
    int lock_ret, unlock_ret;

    lock_ret = mlockall(MCL_CURRENT);
    unlock_ret = munlockall();
}


int
main(void)
{
    mlockall_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Functions-To-Lock-And-Unlock-Pages