#include <stdio.h>
#include <glib.h>

int
main(int argc, char *argv[])
{
        GList *list = NULL;
        list = g_list_append(list, "Hello, World !");
        printf("The first item is '%s'\n", g_list_first(list)->data);

        return 0;
}

/* https://developer.ibm.com/tutorials/l-glib/ */
/* https://stackoverflow.com/questions/11466904/using-glib-library-in-c-program */

/*

$ gcc `pkg-config --cflags --libs glib-2.0` -o g_list_append g_list_append.c
$ ./g_list_append
The first item is 'Hello, World !

*/