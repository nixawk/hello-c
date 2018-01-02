#include <stdio.h>


extern char __executable_start, etext, edata, end;

void
process_layout(void)
{
    printf("executable start: %p\n", &__executable_start);
    printf("etext addr: %p\n", &etext);
    printf("edata addr: %p\n", &edata);
    printf("end addr: %p\n", &end);

    printf("text size: %#x\n", (int)(&etext - &__executable_start)); // right ?
    printf("data size: %#x\n", (int)(&edata - &etext));
    printf("bss  size: %#x\n", (int)(&end - &edata));
}


int
main(void)
{
    process_layout();
    return 0;
}


// https://stackoverflow.com/questions/1765969/where-are-the-symbols-etext-edata-and-end-defined
// https://access.redhat.com/documentation/en-US/Red_Hat_Enterprise_Linux/4/html/Using_ld_the_GNU_Linker/scripts.html
// https://stackoverflow.com/questions/7370407/get-the-start-and-end-address-of-text-section-in-an-executable