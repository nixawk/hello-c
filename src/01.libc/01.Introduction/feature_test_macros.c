/*
 * Various standards govern the behavior of the system call and library function
 * APIs.
 *
 * The following feature test macros are specified by the relevant standards,
 * and consequently their usage is portable to all systems that support these
 * standards:
 *
 * 	_POSIX_SOURCE
 * 	_POSIX_C_SOURCE
 * 	_XOPEN_SOURCE
 *
 * _POSIX_SOURCE:    If defined (with any value), expose definitions conforming
 *                   to POSIX.1-1990 and ISO C (1990). This macro is superseded
 *                   by _POSIX_C_SOURCE.
 *
 * _POSIX_C_SOURCE:  If defined with the value 1, this has the same effect as
 *                   _POSIX_SOURCE.
 *                   If defined with a value greater than or equal to 199309,
 *                   also expose definitions for POSIX.1b (realtime).
 *                   If defined with a value greater than or equal to 199506,
 *                   also expose definitions for POSIX.1c (threads).
 *                   If defined with the value 200112, also expose definitions
 *                   for the POSIX.1-2001 base specification (i.e., the XSI
 *                   extension is excluded).
 *
 * _XOPEN_SOURCE:    If defined (with any value), expose POSIX.1, POSIX.2, and
 *                   X/Open (XPG4) definitions.
 *                   If defined with the value 500 or greater, also expose SUSv2
 *                   (UNIX98 and XPG5) extensions.
 *                   Setting to 600 or greater additionally exposes SUSv3 XSI
 *                   (UNIX 03) extensions and C99 extensions.
 *
 * The following feature test macros listed are glibc-specific:
 *
 * 	_BSD_SOURCE
 * 	_SVID_SOURCE
 * 	_GNU_SOURCE
 *
 * _BSD_SOURCE:      If defined (with any value), expose BSD definitions.
 *                   Defining this macro also defines _POSIX_C_SOURCE with
 *                   the value 199506. Explicitly setting just this macro
 *                   causes BSD definitions to be favored in a few cases
 *                   where standards conflict.
 *
 * _SVID_SOURCE:     If defined (with any value), expose System V Interface
 *                   Definitions (SVID) definitions.
 *
 * _GNU_SOURCE:      If defined (with any value), expose all of the
 *                   definitions provided by setting all of the preceding
 *                   macros, as well as various GNU extensions.
 * */

/* gcc -D_GNU_SOURCE feature_test_macros.c */

#include <errno.h>
#include <stdio.h>

int main(void)
{
#if _GNU_SOURCE
	printf("%s\n", program_invocation_short_name);
#endif
	return 0;
}

