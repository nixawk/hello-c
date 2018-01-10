
// This chapter describes the functions for creating streams and performing
// input and output operations on them. A stream is a fairly abstract,
// high-level concept representing a communications channel to a file, device
// or process.

// For historical reasons, the type of the C data structure that represents
// a stream is called FILE rather than "stream". Since most of the library
// functions deal with objects of type FILE *, sometimes the term file pointer
// is also used to mean "stream". This leads to unfortunate confusion over
// terminology in many books on C.

// The FILE type is declared in header file stdio.h

// struct _IO_FILE {
//   int _flags;           /* High-order word is _IO_MAGIC; rest is flags. */
// #define _IO_file_flags _flags

//   /* The following pointers correspond to the C++ streambuf protocol. */
//   /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
//   char* _IO_read_ptr;   /* Current read pointer */
//   char* _IO_read_end;   /* End of get area. */
//   char* _IO_read_base;  /* Start of putback+get area. */
//   char* _IO_write_base; /* Start of put area. */
//   char* _IO_write_ptr;  /* Current put pointer. */
//   char* _IO_write_end;  /* End of put area. */
//   char* _IO_buf_base;   /* Start of reserve area. */
//   char* _IO_buf_end;    /* End of reserve area. */
//   /* The following fields are used to support backing up and undo. */
//   char *_IO_save_base; /* Pointer to start of non-current get area. */
//   char *_IO_backup_base;  /* Pointer to first valid character of backup area */
//   char *_IO_save_end; /* Pointer to end of non-current get area. */

//   struct _IO_marker *_markers;

//   struct _IO_FILE *_chain;

//   int _fileno;
// #if 0
//   int _blksize;
// #else
//   int _flags2;
// #endif
//   _IO_off_t _old_offset; /* This used to be _offset but it's too small.  */

// #define __HAVE_COLUMN /* temporary */
//   /* 1+column number of pbase(); 0 is unknown. */
//   unsigned short _cur_column;
//   signed char _vtable_offset;
//   char _shortbuf[1];

//   /*  char* _save_gptr;  char* _save_egptr; */

//   _IO_lock_t *_lock;
// #ifdef _IO_USE_OLD_IO_FILE
// };

#include <stdio.h>

void
show_FILE(void)
{
    FILE *stream;

    printf("FILE._fileno = %x\n", stream->_fileno);  /* Tested on Linux */
}

int
main(void)
{
    show_FILE();
    return 0;
}

// typedef struct _IO_FILE FILE;

// https://stackoverflow.com/questions/5672746/what-exactly-is-the-file-keyword-in-c
// https://stackoverflow.com/questions/16424349/where-to-find-struct-io-file
// https://stackoverflow.com/questions/5919996/how-to-detect-reliably-mac-os-x-ios-linux-windows-in-c-preprocessor