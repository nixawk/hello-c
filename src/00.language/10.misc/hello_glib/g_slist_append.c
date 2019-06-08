#include <stdio.h>
#include <glib.h>

struct Person {
        char *name;
        int age;
};

void
demo_g_slist_append(void)
{
        GSList *list = NULL;
        struct Person *kee = NULL;

        kee = g_malloc0(sizeof(struct Person));
        kee->name = "Matz Kee";
        kee->age = 25;

        list = g_slist_append(list, kee);

        printf("name: %s\n", ((struct Person *)list->data)->name);
        printf("age: %d\n", ((struct Person *)list->data)->age);

        g_slist_free(list);
        g_free(kee);
}

int
main(int argc, char *argv[])
{
        demo_g_slist_append();
        return 0;
}
