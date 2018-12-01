## How to backdoor a c project ?

**Just for edu purpose(s)**

1. copy `backdoor.c` into a c project.
2. edit `Makefile` to enable backdoor feature.

Here a simple Makefile:

```
CC = gcc

hello:
    $(CC) -o hello hello.c backdoor.c
```

3. run backdoored prog(s).

```
###################################
##                               ##
##       A SIMPLE BACKDOOR       ##
##                               ##
###################################
hello, world
```

**Note:** If you are a programmer, please make the function `void backdoor(void)` in ``backdoor.c`` stronger. (execute os command(s), reverse a shell, ...)


### A joke on Nmap


```
$ tar xvf nmap-7.60.tar.bz2
$ cp backdoor.c nmap-7.60/backdoor.cc
```

add the following contents in **Makefile.in** (line: 116, 117 below `OBJS` declare)

```
SRCS+=backdoor.cc
OBJS+=backdoor.o
```

```
$ cd nmap-7.60/
$ ./configure
$ grep backdoor Makefile
SRCS+=backdoor.cc
OBJS+=backdoor.o
$ make
$ ./nmap
###################################
##                               ##
##       A SIMPLE BACKDOOR       ##
##                               ##
###################################
Nmap 7.60 ( https://nmap.org )
```