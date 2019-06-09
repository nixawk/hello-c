#include <stdio.h>
#include <glib.h>

void
demo_glib_check_version()
{
        /*
         * NULL if the GLib library is compatible with the given version,
         * or a string describing the version mismatch. The returned string
         * is owned by GLib and must not be modified or freed.
         */
        const gchar *version = glib_check_version(
                GLIB_MAJOR_VERSION,
                GLIB_MINOR_VERSION,
                GLIB_MICRO_VERSION
        );

        if (version == NULL)
                printf(
                        "GLib library is compatible with the given version: %d.%d.%d\n",
                        GLIB_MAJOR_VERSION,
                        GLIB_MINOR_VERSION,
                        GLIB_MICRO_VERSION
                );
}

void
demo_GLIB_CHECK_VERSION()
{
        if (GLIB_CHECK_VERSION(GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION))
                printf(
                        "GLib library is compatible with the given version: %d.%d.%d\n",
                        GLIB_MAJOR_VERSION,
                        GLIB_MINOR_VERSION,
                        GLIB_MICRO_VERSION
                );
}

int
main(int argc, char *argv[])
{
        printf("GLIB_VERSION_MIN_REQUIRED = %d\n", GLIB_VERSION_MIN_REQUIRED);
        printf("GLIB_VERSION_MAX_ALLOWED = %d\n", GLIB_VERSION_MAX_ALLOWED);

        demo_glib_check_version();
        demo_GLIB_CHECK_VERSION();
        return 0;
}

/*
 *
 * GLIB_VERSION_MIN_REQUIRED = 146432
 * GLIB_VERSION_MAX_ALLOWED = 146432
 * GLib library is compatible with the given version: 2.60.3
 * GLib library is compatible with the given version: 2.60.3
 * 
 */
/* https://developer.gnome.org/glib/2.61/glib-Version-Information.html */
