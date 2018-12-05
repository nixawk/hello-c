#include <stdio.h>
#include <stdlib.h>

void preinit(int argc, char **argv, char **envp) {
 printf("%s\n", __FUNCTION__);
}

void init(int argc, char **argv, char **envp) {
 printf("%s\n", __FUNCTION__);
}

void fini() {
 printf("%s\n", __FUNCTION__);
}

__attribute__((section(".init_array"))) typeof(init) *__init = init;
__attribute__((section(".preinit_array"))) typeof(preinit) *__preinit = preinit;
__attribute__((section(".fini_array"))) typeof(fini) *__fini = fini;

void  __attribute__ ((constructor)) constructor() {
 printf("%s\n", __FUNCTION__);
}

void __attribute__ ((destructor)) destructor() {
 printf("%s\n", __FUNCTION__);
}

void my_atexit() {
 printf("%s\n", __FUNCTION__);
}

void my_atexit2() {
 printf("%s\n", __FUNCTION__);
}

int main() {
 atexit(my_atexit);
 atexit(my_atexit2);
}

/*

code@lab:~/elf$ gcc elf_load.c 
code@lab:~/elf$ ./a.out 
preinit
init
constructor
my_atexit2
my_atexit
destructor
fini

*/

// https://www.cs.stevens.edu/~jschauma/810/elf.html