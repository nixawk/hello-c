#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdio.h>   /* for stand input/output */
#include <errno.h>   /* for definition of errno */
#include <string.h>  /* for functions of string */
#include <stdarg.h>  /* ISO C variable arguments */
#include <limits.h>  /* platform limits */
#include <stdlib.h>

void err_ret(const char *, ...);
void err_sys(const char *, ...);
void err_cont(int, const char *, ...);
void err_exit(int, const char *, ...);
void err_dump(const char *, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);

static void err_doit(int, int, const char *, va_list);


#endif