CC = gcc

all: hello_dlopen library

hello_dlopen:
	$(CC) -Wall -o hello_dlopen -rdynamic -ldl hello_dlopen.c

library:
	$(CC) -Wall -o library.so -shared -fpic library.c

clean:
	rm -rf hello_dlopen
	rm -rf library.so