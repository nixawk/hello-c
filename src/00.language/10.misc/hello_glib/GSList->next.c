#include <stdio.h>
#include <glib.h>

void
demo_GSList_next(void)
{
        GSList *list = NULL;

        list = g_slist_append(list, "first");
        list = g_slist_append(list, "second");
        list = g_slist_append(list, "third");

        for (GSList *iterator = list; iterator; iterator = iterator->next) {
                printf("value : %s\n", iterator->data);
        }

        g_slist_free(list);
}

int
main(int argc, char *argv[])
{
        demo_GSList_next();
        return 0;
}