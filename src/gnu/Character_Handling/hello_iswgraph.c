#include <wctype.h>
#include <wchar.h>
#include <stdio.h>


// int iswgraph (wint_t wc)

// Returns true if wc is a graphic character; that is, a character that has a glyph associated with it.
// The whitespace characters are not considered graphic.

// This function can be implemented using

    // iswctype (wc, wctype ("graph"))


void
iswgraph_usage(void)
{
    wchar_t string[] = L"hello, world";
    int i;

    for (i = 0; i < wcslen(string); i++)
    {
        if (iswgraph(string[i]))
        {
            printf("[%c] is a graphic character.\n", string[i]);
        } else {
            printf("[%c] is not a graphic character.\n", string[i]);
        }
    }
}


int
main(void)
{
    iswgraph_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters