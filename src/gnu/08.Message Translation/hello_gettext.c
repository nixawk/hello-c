#include <libintl.h>
#include <errno.h>
#include <stdio.h>

// The gettext approach has some advantages but also some disadvantages.
// Please see the GNU gettext manual for a detailed discussion of the pros
// and cons.

    // char * gettext (const char *msgid)

// The gettext function searches the currently selected message catalogs
// for a string which is equal to msgid. If there is such a string available
// it is returned. Otherwise the argument string msgid is returned.

// Please note that although the return value is cjar * the returned string
// must not be changed. This broken type results from the history of the
// function and does not reflect the wat the function should be ised.

// Please note that above we wrote "message catalogs" (plural). This is a
// specialty of the GNU implementation of these function and we will say
// more about this when we talk about the ways message catalogs are selected


    // char * dgettext (const char *domainname, const char *msgid)

// The dgettext function acts just like the gettext function. It only takes
// an additional first domainname which guides the selection of the message
// catalogs which are searched for the translation. If the domainname parameter
// is the null pointer the dgettext function is exactly equivalent to gettext
// since the default value for the domain name is used.

// As for gettext the return value type is char * which is an anachronism.
// The returned string must string never be modified.

    // char * dcgettext (const char *domainname, const char *msgid, int category)


void
gettext_usage(void)
{
    errno = 1;
    printf(gettext("Operation failed: %m\n"));

    // Operation failed: Operation not permitted.

    // The gettext function does not modify the value of the global errno
    // variable. Here errno value is used in the printf function while
    // processing the %m format element and if the gettext function
    // would change this value (it is called before printf is called)
    // we would get a wrong message.
}


int
main(void)
{
    gettext_usage();
    return 0;
}