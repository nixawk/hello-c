#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/procfs.h>


void
nogdb(char *filename)
{
    int f;
    static Elf32_Ehdr* elfhdr;

    if ((f = open(filename, O_RDWR)) < 0)
    {
        perror("open");
        exit(1);
    }

    //MAP_SHARED is required to actually update the file
    elfhdr = (Elf32_Ehdr *) mmap(
        NULL,
        sizeof(elfhdr),
        PROT_READ | PROT_WRITE, MAP_SHARED,
        f,
        0
    );

    if (elfhdr == MAP_FAILED)
    {
        perror("mmap");
        close(f);
        exit(1);
    }

    printf("[*] Current elfhdr values:\n");
    printf("\te_shoff:%d\n\te_shnum:%d\n\te_shstrndx:%d\n",
            elfhdr->e_shoff, elfhdr->e_shnum, elfhdr->e_shstrndx);

    elfhdr->e_shoff = 0xffff;
    elfhdr->e_shnum = 0xffff;
    elfhdr->e_shstrndx = 0xffff;

    printf("[*] Patched elfhdr values:\n");
    printf("\te_shoff:%d\n\te_shnum:%d\n\te_shstrndx:%d\n",
            elfhdr->e_shoff, elfhdr->e_shnum, elfhdr->e_shstrndx);

    if (msync(NULL, 0, MS_SYNC) == -1)
    {
        perror("msync");
        close(f);
        exit(1);
    }

    close(f);
    munmap(elfhdr, 0);
}


int
main(int argc, char** argv)
{
    if(argc < 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    nogdb(argv[1]);

    return 0;
}


/*

code@lab:~/src/mirai$ gcc hello_nogdb.c -o hello_nogdb 
code@lab:~/src/mirai$ gcc hello.c -o hello
code@lab:~/src/mirai$ ./hello
hello, world
code@lab:~/src/mirai$ ./hello_nogdb ./hello
[*] Current elfhdr values:
    e_shoff:64
    e_shnum:0
    e_shstrndx:0
[*] Patched elfhdr values:
    e_shoff:65535
    e_shnum:65535
    e_shstrndx:65535
You should no more be able to run "./hello" inside GDB
code@lab:~/src/mirai$ ./hello
bash: ./hello: cannot execute binary file: Exec format error

*/

// http://llvm.org/doxygen/BinaryFormat_2ELF_8h_source.html