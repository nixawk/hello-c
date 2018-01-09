// One of the most basic resources a process has available to it is memory.
// There are a lot of different ways systems organize memory, but in a typical
// one, each process has one linear virtual address space, with addresses running
// from zero to some huge maximum. It need not be contiguous; i.e., not all of
// these addresses actually can be used ti store data.

// The virtual memory is divided into pages (4 kilobytes is typical). Backing 
// each page of virtual memory is a page of real memory (called a frame) or 
// some secondary storage, usually disk space. The disk space might be swap 
// space or just some ordinary disk file. Actually, a page of all zeroes 
// sometimes has nothing at all backing it – there’s just a flag saying 
// it is all zeroes.

// In order for a program to access any part of a virtual page, the page must
// at that moment be backed by (“connected to”) a real frame. But because there
// is usually a lot more virtual memory than real memory, the pages must move 
// back and forth between real memory and backing store regularly, coming into
// real memory when a process needs to access them and then retreating to backing
// store when not needed anymore. This movement is called paging.

// When a program attempts to access a page which is not at that moment backed by
// real memory, this is known as a [page fault]. When a page fault occurs, the kernel
// suspends the process, places the page into a real page frame (this is called 
//“paging in” or “faulting in”), then resumes the process so that from the process’
// point of view, the page was in real memory all along. In fact, to the process,
// all pages always seem to be in real memory. Except for one thing: the elapsed
// execution time of an instruction that would normally be a few nanoseconds is
// suddenly much, much, longer (because the kernel normally has to do I/O to complete
// the page-in). For programs sensitive to that, the functions described in Locking
// Pages can control it.

// Processes allocate memory in two major ways: by exec and programmatically. Actually,
// forking is a third way, but it’s not very interesting.

// Exec is the operation of creating a virtual address space for a process, loading its
// basic program into it, and executing the program. It is done by the “exec” family of
// functions (e.g. execl). The operation takes a program file (an executable), it allocates
// space to load all the data in the executable, loads it, and transfers control to it.
// That data is most notably the instructions of the program (the text), but also literals
// and constants in the program and even some variables: C variables with the static storage class

// Once that program begins to execute, it uses programmatic allocation to gain additional memory.

// Memory-mapped I/O is another form of dynamic virtual memory allocation. Mapping memory to
// a file means declaring that the contents of certain range of a process’ addresses shall
// be identical to the contents of a specified regular file. The system makes the virtual
// memory initially contain the contents of the file, and if you modify the memory, the
// system writes the same modification to the file. Note that due to the magic of virtual
// memory and page faults, there is no reason for the system to do I/O to read the file,
// or allocate real memory for its contents, until the program accesses the virtual memory.
// See Memory-mapped I/O.

// Just as it programmatically allocates memory, the program can programmatically
// deallocate (free) it. You can’t free the memory that was allocated by exec.
// When the program exits or execs, you might say that all its memory gets freed,
// but since in both cases the address space ceases to exist, the point is really
// moot. See Program Termination.

// A process’ virtual address space is divided into segments. A segment is a contiguous
// range of virtual addresses. Three important segments are:

    // The [text] segment contains a program’s instructions and literals and static constants.
    // It is allocated by exec and stays the same size for the life of the virtual address space.

    // The [data] segment is working storage for the program. It can be preallocated and preloaded
    // by exec and the process can extend or shrink it by calling functions as described in See
    // Resizing the Data Segment. Its lower end is fixed.

    // The stack segment contains a program stack. It grows as the stack grows, but doesn’t shrink
    // when the stack shrinks.


// https://www.gnu.org/software/libc/manual/html_node/Memory-Concepts.html#Memory-Concepts