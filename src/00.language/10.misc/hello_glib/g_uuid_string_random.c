#include <stdio.h>
#include <glib.h>
#include <glib/gi18n.h>

void
demo_g_uuid_string_random(void)
{
        printf("uuid = %s\n", g_uuid_string_random());
}

int
main(void)
{
        demo_g_uuid_string_random();
        return 0;
}

/* https://developer.gnome.org/glib/2.61/glib-GUuid.html */
