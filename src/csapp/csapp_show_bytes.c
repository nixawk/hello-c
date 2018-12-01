#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
        size_t i;
        for (i = 0; i < len; i++)
                printf(" %.2x", start[i]);
        printf("\n");
}

void show_int(int x)
{
        show_bytes((byte_pointer)&x, sizeof(x));
}

void show_float(float x)
{
        show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void *x)
{
        show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
        int   ival  = val;
        float fval  = (float) ival;
        int   *pval = &ival;

        show_int(ival);
        show_float(fval);
        show_pointer(pval);
}


int
main()
{
        return 0;
}


/*

-[ functions ]----------------                              Visual code review (pdf)
(a) add     (x)xrefs     (q)quit                            / (fcn) sym.show_bytes 26
(r) rename  (c)calls     (g)go                              |   sym.show_bytes ();
(d) delete  (v)variables (?)help                            |           ; var int local_20h @ rbp-0x20
   0x557e7c0c75b0   16 sym.imp.__cxa_finalize               |           ; var int local_18h @ rbp-0x18
   0x557e7c0c76c0   42 sym.frame_dummy                      |           ; var int local_8h @ rbp-0x8
   0x557e7c0c7830    2 sym.__libc_csu_fini                  |              ; CALL XREF from 0x557e7c0c7782 (sym.show_float)
   0x557e7c0c7834    9 sym._fini                            |              ; CALL XREF from 0x557e7c0c7761 (sym.show_int)
   0x557e7c0c77c0  101 sym.__libc_csu_init                  |              ; CALL XREF from 0x557e7c0c77a2 (sym.show_pointer)
 * 0x557e7c0c76f0   26 sym.show_bytes                       |           0x557e7c0c76f0      push rbp
   0x557e7c0c7769   33 sym.show_float                       |           0x557e7c0c76f1      mov rbp, rsp
>  0x557e7c0c774a   31 sym.show_int                         |           0x557e7c0c76f4      sub rsp, 0x20
   0x557e7c0c778a   32 sym.show_pointer                     |           0x557e7c0c76f8      mov qword [local_18h], rdi
   0x557e7c0c7570   23 sym._init                            |           0x557e7c0c76fc      mov qword [local_20h], rsi
   0x557e7c0c75a0    8 sym.imp.putchar                      |           0x557e7c0c7700      mov qword [local_8h], 0
   0x557e7c0c75a8    8 sym.imp.printf                       \       ,=< 0x557e7c0c7708      jmp 0x557e7c0c7733                     ;[gq]

*/