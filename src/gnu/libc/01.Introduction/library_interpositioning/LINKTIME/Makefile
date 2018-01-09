CC = gcc

linktime: mymalloc
	$(CC) -Wall -c hello_intpos.c
	$(CC) -Wall -Wl,--wrap,malloc -Wl,--wrap,free -o hello_intpos hello_intpos.o mymalloc.o

mymalloc:
	$(CC) -Wall -DLINKTIME -c mymalloc.c

clean:
	rm -rf mymalloc.o hello_intpos.o
	rm -rf hello_intpos
