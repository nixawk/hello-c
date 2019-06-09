#include <stdio.h>
#include <glib.h>

void
demo_G_OS_UNIX(void)
{
#ifdef G_OS_UNIX
        printf("The os is unix\n");
#elif G_OS_WIN32
        printf("The os is windows\n")
#else
        printf("The os is not supported\n");
#endif
}

int
main(void)
{
        demo_G_OS_UNIX();
        return 0;
}

/* https://developer.gnome.org/glib/2.61/glib-Standard-Macros.html */