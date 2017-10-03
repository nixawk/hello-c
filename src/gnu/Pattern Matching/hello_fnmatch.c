#include <fnmatch.h>
#include <stdio.h>

// int fnmatch (const char *pattern, const char *string, int flags)

// This function tests whether the string [string] matches the pattern.
// It returns 0 if they do match; otherwise, it returns the nonzero value [FNM_NOMATCH].

// The arguments pattern and string are both strings.
// The argument flags is a combination might sometimes report "errors" by returning nonzero
// values that are not equal to [FNM_NOMATCH]

    // FNM_FILE_NAME
    // FNM_PATHNAME
    // FNM_PERIOD
    // FNM_NOESCAPE
    // FNM_LEADING_DIR
    // FNM_CASEFOLD
    // FNM_EXTMATCH

void
fnmatch_usage(void)
{
    if (0 == fnmatch("hello*", "HELLO world", FNM_CASEFOLD))
    {
        printf("match\n");
    }
}


int
main(void)
{
    fnmatch_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Wildcard-Matching.html#Wildcard-Matching