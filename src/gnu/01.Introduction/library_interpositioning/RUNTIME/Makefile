CC = gcc

all: runtime mymalloc

runtime:
	$(CC) -Wall -o hello_intpos hello_intpos.c

mymalloc:
	$(CC) -Wall -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl