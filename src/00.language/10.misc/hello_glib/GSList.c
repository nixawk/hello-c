#include <stdio.h>
#include <glib.h>

void
singly_linked_lists(void)
{
        GSList * list = NULL;

        printf("The list is now %d items long\n", g_slist_length(list));
        list = g_slist_append(list, "first");
        list = g_slist_append(list, "second");
        printf("The list is now %d items long\n", g_slist_length(list));
        g_slist_free(list);
}

int
main(int argc, char *argv[])
{
        singly_linked_lists();
        return 0;
}

/* https://developer.ibm.com/tutorials/l-glib/ */