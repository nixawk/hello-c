#include <unistd.h>


// void sync (void)

// A call to this function will not return as long as there is data which has not been
// written to the device. All dirty buffers in the kernel will be written and so
// overall consistant system can be archieved (if no other process in parallel writes
// data)

// Programs more often want to ensure that data written to a given file is committed,
// rather than all data in the system. For this [sync] is overkill.

void
sync_usage(void)
{
    sync();
}


int
main(void)
{
    sync_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Synchronizing-I_002fO.html