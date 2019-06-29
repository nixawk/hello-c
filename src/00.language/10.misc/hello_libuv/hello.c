#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

int main()
{
        uv_loop_t *loop = malloc(sizeof(uv_loop_t));
        uv_loop_init(loop);

        printf("Now quitting.\n");
        uv_run(loop, UV_RUN_DEFAULT);

        uv_loop_close(loop);
        free(loop);
        return 0;
}

/*
 * $ gcc `pkg-config --libs libuv` hello.c
 * Now quitting.
 */

/* https://github.com/libuv/libuv */
/* https://libuv.org/ */
/* http://docs.libuv.org/en/v1.x/ */
/* http://docs.libuv.org/en/v1.x/guide/basics.html */