#include <stdio.h>
#include <glib.h>

void
demo_g_slist_prepend(void)
{
        GSList *list = NULL;
        list = g_slist_append(list, "second");
        list = g_slist_prepend(list, "first"); /* 1st item */
        
        printf("The first item is '%s'\n", g_slist_nth_data(list, 0));
        g_slist_free(list);
}

int
main(int argc, char *argv[])
{
        demo_g_slist_prepend();
        return 0;
}

/* gcc `pkg-config --cflags --libs glib-2.0` g_list_prepend.c */