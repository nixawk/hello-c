#include <stdio.h>

extern char etext, edata, end;

void
process_layout(void)
{
    printf("etext addr: %p\n", &etext); // addr of the end of the program text
    printf("edata addr: %p\n", &edata); // addr of the end of the program data
    printf("end addr: %p\n", &end);
}


int
main(void)
{
    process_layout();
    return 0;
}


// https://stackoverflow.com/questions/1765969/where-are-the-symbols-etext-edata-and-end-defined
// https://access.redhat.com/documentation/en-US/Red_Hat_Enterprise_Linux/4/html/Using_ld_the_GNU_Linker/scripts.html