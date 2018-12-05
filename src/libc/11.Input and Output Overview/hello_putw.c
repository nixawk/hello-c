#include <stdio.h>

// int putw (int w, FILE *stream)

// This function writes the word w (that is, an int) to stream. It is provided for compatibility with SVID,
// but we recommend you use fwrite instead (see Block Input/Output).

void putw_usage(void)
{
	int w = 0x41414141;

	putw(w, stdout);	// print "AAAA"
}

int main(void)
{
	putw_usage();
	return 0;
}
