#include <iconv.h>
#include <wchar.h>
#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Data Type: iconv_t

// This data type is an abstract type defined in iconv.h. The user must not
// assume anything about the definition of this type; it must be completely
// opaque.

// Objects of this type can be assigned handles for the conversions using
// the iconv functions. The objects themselves need not be freed, but the
// conversions for which the handles stand for have to.

    // iconv_t iconv_open (const char *tocode, const char *fromcode)

// The iconv_open function has to be used before starting a conversion.
// The two parameters this function takes determine the source and
// destination character set for the conversion, and if the implementation
// has the possibility to perform such a conversion, the function returns
// a handle.

    // EMFILE - The process already has OPEN_MAX file descriptors open.
    // ENFILE - The system limit of open files is reached.
    // ENOMEM - Not enough memory to carry out the operation.
    // EINVAL - The conversion from fromcode to tocode is not supported.

    // int iconv_close (iconv_t cd)

// The iconv_close function frees all resources associated with the handle cd,
// which must have been returned by a successful call to the iconv_open
// function.

    // EBADF - The conversion descriptor is invalid.

    // size_t iconv (iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft)

int file2wcs(int fd, const char *charset, wchar_t * outbuf, size_t avail)
{
	char inbuf[BUFSIZ];
	size_t insize = 0;
	char *wrptr = (char *)outbuf;
	int result = 0;
	iconv_t cd;

	cd = iconv_open("WCHAR_T", charset);
	if (cd == (iconv_t) - 1) {
		/* Something went wrong.  */
		if (errno == EINVAL)
			error(0, 0,
			      "conversion from '%s' to wchar_t not available",
			      charset);
		else
			perror("iconv_open");

		/* Terminate the output string.  */
		*outbuf = L'\0';

		return -1;
	}

	while (avail > 0) {
		size_t nread;
		size_t nconv;
		char *inptr = inbuf;

		/* Read more input.  */
		nread = read(fd, inbuf + insize, sizeof(inbuf) - insize);
		if (nread == 0) {
			/* When we come here the file is completely read.
			   This still could mean there are some unused
			   characters in the inbuf.  Put them back.  */
			if (lseek(fd, -insize, SEEK_CUR) == -1)
				result = -1;

			/* Now write out the byte sequence to get into the
			   initial state if this is necessary.  */
			iconv(cd, NULL, NULL, &wrptr, &avail);

			break;
		}
		insize += nread;

		/* Do the conversion.  */
		nconv = iconv(cd, &inptr, &insize, &wrptr, &avail);
		if (nconv == (size_t) - 1) {
			/* Not everything went right.  It might only be
			   an unfinished byte sequence at the end of the
			   buffer.  Or it is a real problem.  */
			if (errno == EINVAL)
				/* This is harmless.  Simply move the unused
				   bytes to the beginning of the buffer so that
				   they can be used in the next round.  */
				memmove(inbuf, inptr, insize);
			else {
				/* It is a real problem.  Maybe we ran out of
				   space in the output buffer or we have invalid
				   input.  In any case back the file pointer to
				   the position of the last processed byte.  */
				lseek(fd, -insize, SEEK_CUR);
				result = -1;
				break;
			}
		}
	}

	/* Terminate the output string.  */
	if (avail >= sizeof(wchar_t))
		*((wchar_t *) wrptr) = L'\0';

	if (iconv_close(cd) != 0)
		perror("iconv_close");

	return (wchar_t *) wrptr - outbuf;
}

int main(void)
{
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Generic-Charset-Conversion
