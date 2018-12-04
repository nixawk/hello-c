/*
 * The intent of the inline specifier is to serve as a hint for the compiler
 * to perform optimization, such as function inlining. which require the
 * definition of function to be visible at the call site. The compilers can
 * (and usually do) ignore presence or absence of the inline specifier for
 * the purpose of optimization.
 *
 * */

#include "inline.h"

extern inline void keyword_inline(void);

int main(void)
{
	keyword_inline();	/* the compiler will copy code here */
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/inline */
/* https://en.cppreference.com/w/c/language/inline */
