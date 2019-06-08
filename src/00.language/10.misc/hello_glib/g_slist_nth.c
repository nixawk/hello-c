#include <stdio.h>
#include <glib.h>

void
demo_g_slist_nth(void)
{
        GSList *list = NULL;

        list = g_slist_append(list, "first");
        list = g_slist_append(list, "second");
        list = g_slist_append(list, "third");

        printf("\n----g_slist_nth\n");
        printf("[*] 2nd item value: %s\n", g_slist_nth(list, 0)->data);
        printf("[*] 2nd item value: %s\n", g_slist_nth(list, 1)->data);
        printf("[*] 2nd item value: %s\n", g_slist_nth(list, 2)->data);
        printf("\n----g_slist_nth_data\n");
        printf("[*] 2nd item value: %s\n", g_slist_nth_data(list, 0));
        printf("[*] 2nd item value: %s\n", g_slist_nth_data(list, 1));
        printf("[*] 2nd item value: %s\n", g_slist_nth_data(list, 2));

        g_slist_free(list);

}

int
main(int argc, char *argv[])
{
        demo_g_slist_nth();
        return 0;
}