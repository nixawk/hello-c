#include <stdio.h>
#include <glib.h>

typedef struct Thread_Args {
        gchar *s;
        int n;
} Thread_Args_t;

gpointer thread_job(gpointer data)
{
        struct Thread_Args *t_args = (struct Thread_Args *)data;
        gint retval = 1;

        printf("s = %s\n", t_args->s);
        printf("n = %d\n", t_args->n);

        // g_usleep(2000000);

        g_thread_exit((gpointer)&retval);

        return NULL;
}

void
demo_g_thread_new(void)
{
        for (gint i = 0; i < 5; i++)
        {
                Thread_Args_t *t_args = g_malloc0(sizeof(struct Thread_Args));

                t_args->s = "This is a thread message";
                t_args->n = i;
 
                GThread *thread = g_thread_new(
                        "thread",
                        thread_job,
                        (gpointer)t_args
                );
                g_thread_join(thread);

                if (t_args)
                        g_free(t_args);
        }

}

int
main(void)
{
        demo_g_thread_new();
        return 0;
}

/*

$ ./a.out
s = This is a thread message
n = 0
s = This is a thread message
n = 1
s = This is a thread message
n = 2
s = This is a thread message
n = 3
s = This is a thread message
n = 4

*/

/* https://developer.gnome.org/glib/stable/glib-String-Utility-Functions.html#g-strconcat */
/* https://developer.gnome.org/glib/2.61/glib-Message-Logging.html */
