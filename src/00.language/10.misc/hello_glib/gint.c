#include <stdio.h>
#include <glib.h>

void
demo_gint(void)
{
        gint n = 0;

        printf("sizeof(gint) = %ld\n", sizeof(n));
        printf("G_MININT = %d\n", G_MININT);
        printf("G_MAXINT = %d\n", G_MAXINT);
}

int
main(int argc, char *argv[])
{
        demo_gint();
        return 0;
}

/*
 * sizeof(gint) = 4
 * G_MININT = -2147483648
 * G_MAXINT = 2147483647
 */

/* https://developer.gnome.org/glib/2.61/glib-Basic-Types.html */
