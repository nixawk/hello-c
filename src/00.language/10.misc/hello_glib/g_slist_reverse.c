#include <stdio.h>
#include <glib.h>

void
demo_g_slist_reverse(void)
{
        GSList *list;


        list = g_slist_append(list, "first");
        list = g_slist_append(list, "second");

        printf("1st value: %s\n", g_slist_nth_data(list, 0));
        list = g_slist_reverse(list);
        printf("1st value: %s\n", g_slist_nth_data(list, 0));

        g_slist_free(list);
}

int
main(void)
{
        demo_g_slist_reverse();
        return 0;
}
