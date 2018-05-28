#include <unistd.h>
#include "error.h"


// This is a demo file for error handler.

void
demo(void)
{
	access("invalid-file-path", R_OK);

	err_msg("err_msg: this is an error message");  /* output */
	err_ret("err_ret");                            /* output */
	err_cont(1, "err_cont");                       /* output */

	err_sys("err_sys");        /* never output */
	err_quit("err_quit");      /* never output */
	err_exit(1, "err_exit");   /* never output */
}

int
main(void)
{
	demo();

	return 0;
}