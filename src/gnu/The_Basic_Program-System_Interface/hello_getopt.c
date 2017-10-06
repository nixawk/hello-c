#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// If the syntax for the command line arguments to your program is simple enough,
// you can simply pick the arguments off from [argv] by hand. But unless your
// program takes a fixed number of arguments, or all of the arguments are interpreted
// in the same way, you are usually better off using [getopt] or [arg_parse] to do
// the parsing.

// -- [getopt]

// [int opterr]
// If the value of this variable is nonzero, then [getopt] prints an error message
// to the standard error stream if it encounters an unknown option character or 
// an option with a missing required argument. This is the default behavior. 
// If you set this variable to zero, getopt does not print any messages, but
//  it still returns the character ? to indicate an error.

// [int optopt]
// When getopt encounters an unknown option character or an option with a missing 
// required argument, it stores that option character in this variable. You can 
// use this for providing your own diagnostic messages.

// [int optind]
// This variable is set by getopt to the index of the next element of the argv 
// array to be processed. Once getopt has found all of the option arguments, 
// you can use this variable to determine where the remaining non-option arguments
//  begin. The initial value of this variable is 1.

// [char * optarg]
// This variable is set by getopt to point at the value of the option argument, 
// for those options that accept arguments.

// -- [getopt]

// int getopt (int argc, char *const *argv, const char *options)

// The [getopt] function gets the next option argument from the argument list
// specified by the [argv] and [argc] arguments. Normally these values come
// directly from the arguments received by [main].

// The [options] argument is a string that specifies the option characters that
// are valid for this program. An option character in this string can be followed
// by a colon (':') to indicate that it takes a required argument. If an option
// character is followed by two colons ('::'), its argument is optional;
// this is a GNU extension.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "abc:")) != -1)
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html#Argument-Syntax
// https://www.gnu.org/software/libc/manual/html_node/Parsing-Program-Arguments.html#Parsing-Program-Arguments
// https://www.gnu.org/software/libc/manual/html_node/Getopt.html#Getopt
// https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html#Using-Getopt
// https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html#Example-of-Getopt