#include <stdio.h>
#include <glib.h>

void
demo_g_slist_remove_all(void)
{
        GSList * list = NULL;

        printf("The list is now %d items long\n", g_slist_length(list));

        list = g_slist_append(list, "first");
        list = g_slist_append(list, "second");
        list = g_slist_append(list, "second");
        list = g_slist_append(list, "third");
        list = g_slist_append(list, "third");
        printf("The list is now %d items long\n", g_slist_length(list));

        list = g_slist_remove(list, "second");  /* remove the first one */
        printf("The list is now %d items long\n", g_slist_length(list));

        list = g_slist_remove_all(list, "third");
        printf("The list is now %d items long\n", g_slist_length(list));

        g_slist_free(list);
}

int
main(int argc, char *argv[])
{
        demo_g_slist_remove_all();
        return 0;
}

/* https://developer.ibm.com/tutorials/l-glib/ */