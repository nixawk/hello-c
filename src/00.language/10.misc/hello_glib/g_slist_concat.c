#include <stdio.h>
#include <glib.h>

void
demo_g_slist_concat(void)
{
        GSList *list1 = NULL;
        GSList *list2 = NULL;
        GSList *list12 = NULL;

        list1 = g_slist_append(list1, "first");
        list1 = g_slist_append(list1, "second");

        list2 = g_slist_append(list2, "third");
        list2 = g_slist_append(list2, "fourth");

        list12 = g_slist_concat(list1, list2);

        printf("The length of list12: %d\n", g_slist_length(list12));
        printf("The first of list12 : %s\n", g_slist_nth_data(list12, 0));
        printf("The last of list12  : %s\n", g_slist_last(list12)->data);

        g_slist_free(list1);
        g_slist_free(list2);
        g_slist_free(list12);
}

int
main(int argc, char *argv[])
{
        demo_g_slist_concat();
        return 0;
}