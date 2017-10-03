#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

    // int regcomp (regex_t *restrict compiled, const char *restrict pattern, int cflags)

// The function [regcomp] compiles a regular expression into a data structure
// that you can use with [regexec] to match against a string. The compiled
// regular expression format is designed for efficient matching. [regcomp]
// stores it into [*compiled].

// The argument [cflags] lets you specify various options that control the syntax and
// semantics of regular expressions.

// [regcomp] returns 0 if it succeeds in compiling the regular expression; otherwise,
// it returns a nonzero error code. You can use [regerror] to produce an error message
// string describing the reason for a nonzero value. Here are the possible nonzero values
// that [regcomp] can return:

    // REG_BADBR
    // REG_BADPAT
    // REG_BADRPT
    // REG_ECOLLATE
    // REG_ECTYPE
    // REG_EESCAPE
    // REG_ESUBREG
    // REG_EBRACK
    // REG_EPAREN
    // REG_EBRACE
    // REG_ERANGE
    // REG_ESPACE

//////////

    // int regexec (const regex_t *restrict compiled, const char *restrict string, size_t nmatch, regmatch_t matchptr[restrict], int eflags)

// This function tries to match the compiled regular expression [*compiled] against string.
// [regexec] returns 0 if the regular expression matches; otherwise, it returns a nonzero value.

// The argument [eflags] is a word of bit flags that enable various options.

    // REG_NOTBOL
    // REG_NOTEOL

// If you want to get information about what part of string actually matched the regular expression or its subexpressions, 
// use the arguments matchptr and nmatch. Otherwise, pass 0 for nmatch, and NULL for matchptr.

    // void regfree (regex_t *compiled)


void
regex_usage(void)
{
    regex_t    preg;
    char       *string = "a simple string";
    char       *pattern = ".*(simple).*";
    int        rc;
    size_t     nmatch = 2;
    regmatch_t pmatch[2];

    if ((rc = regcomp(&preg, pattern, REG_EXTENDED)) != 0) {
        printf("regcomp() failed, returning nonzero (%d)\n", rc);
        exit(1);
    }

    if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {
        printf("failed to ERE match '%s' with '%s',returning %d.\n", string, pattern, rc);
    }

    printf(
        "a matched substring \"%.*s\" is found at position %d to %d.\n",
        pmatch[1].rm_eo - pmatch[1].rm_so, &string[pmatch[1].rm_so],
        pmatch[1].rm_so,
        pmatch[1].rm_eo - 1); 

    regfree(&preg);
}


int
main(void)
{
    regex_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/POSIX-Regexp-Compilation.html#POSIX-Regexp-Compilation
// https://www.gnu.org/software/libc/manual/html_node/Flags-for-POSIX-Regexps.html#Flags-for-POSIX-Regexps
// https://www.gnu.org/software/libc/manual/html_node/Matching-POSIX-Regexps.html#Matching-POSIX-Regexps
// https://www.gnu.org/software/libc/manual/html_node/Regexp-Subexpressions.html#Regexp-Subexpressions
// https://www.gnu.org/software/libc/manual/html_node/Regexp-Cleanup.html#Regexp-Cleanup
// https://www.ibm.com/support/knowledgecenter/SSLTBW_1.13.0/com.ibm.zos.r13.bpxbd00/regexep.htm
// https://stackoverflow.com/questions/17764422/regmatch-t-how-can-i-get-match-only