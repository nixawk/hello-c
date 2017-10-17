CC = gcc

compiletime: mymalloc
	$(CC) -I. -o intpos_compile hello_intpos.c mymalloc.o

mymalloc:
	$(CC) -DCOMPILETIME -c mymalloc.c

clean:
	rm -rf mymalloc.o
	rm -rf intpos_compile