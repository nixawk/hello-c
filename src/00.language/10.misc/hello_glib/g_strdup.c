#include <stdio.h>
#include <glib.h>

void
demo_strdup(void)
{
        gchar *s1 = "hello";
        gchar *d1 = g_strdup(s1);
        gchar *d2 = g_strdup(s1);

        printf("s1: %p\n", s1);
        printf("d1: %p\n", d1);
        printf("d2: %p\n", d2);

        if (d1)
                g_free(d1);

        if (d2)
                g_free(d2);

}

int
main(void)
{
        demo_strdup();
        return 0;
}

/*
 * ./a.out
 * s1: 0x10448ef8e
 * d1: 0x7fb9779070c0
 * d2: 0x7fb977906f20
 */