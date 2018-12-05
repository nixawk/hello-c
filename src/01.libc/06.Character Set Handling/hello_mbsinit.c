#include <wchar.h>
#include <string.h>
#include <stdio.h>

// Data type: mbstate_t

// A variable of type mbstate_t can contain all the information about
// the shift state needed from one call to a conversion function to
// another.

// mbstate_t is defined in wchar_t.h. It was introduced in Amendment
// 1 to ISO C90.

// int mbsinit (const mbstate_t *ps)

// The mbsinit function determines whether the state object pointed to
// by ps is in the initial state. If ps is a null pointer or the object
// is in the initial state the return value is nonzero. Otherwise it is
// zero. mbsinit was introduced in Amendment 1 to ISO C90 and is
// declared in wchar.h

#define SIZE 512

void mbsinit_usage(void)
{
	char outbuf[SIZE];
	int outbuflen = strlen(outbuf);

	mbstate_t state;
	memset(&state, '\0', sizeof(state));

	if (!mbsinit(&state)) {
		const wchar_t empty[] = L"ABCD";
		const wchar_t *srcp = empty;

		wcsrtombs(outbuf, &srcp, outbuflen, &state);
		printf("%s\n", outbuf);
	}
}

int main(void)
{
	mbsinit_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
