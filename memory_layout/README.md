
## User space VS Kernel Space

A modern computer operating system usually segregates virtual memory into kernel space and user space. Primarily, this separation serves to provide memory protection and hardware protection from malicious or errant software behaviour.

**Kernel space** is strictly reserved for running a privileged operating system kernel, kernel extensions, and most device drivers. In contrast, **user space** is the memory area where application software and some drivers execute.


The term userland (or user space) refers to all code that runs outside the operating system's kernel. Userland usually refers to the various programs and libraries that the operating system uses to interact with the kernel: software that performs input/output, manipulates file system objects, application software, etc.

Each user space process normally runs in its own virtual memory space, and, unless explicitly allowed, cannot access the memory of other processes. This is the basis for memory protection in today's mainstream operating systems, and a building block for privilege separation. A separate user mode can also be used to build efficient virtual machines. Depending on the privileges, processes can request the kernel to map part of another process's memory space to its own, as is the case for debuggers. Programs can also request shared memory regions with other processes, although other techniques are also available to allow inter-process communication.

![](https://user-images.githubusercontent.com/7352479/29762625-6fb2630e-8b9d-11e7-9c71-ea98dd4ec1e2.png)


## Memory Layout In C


Please use x86 platform or **-m32** to compile progs.

```
root@sh:~/debug/memory_layout# uname -a
Linux sh 4.6.0-kali1-686-pae #1 SMP Debian 4.6.4-1kali1 (2016-07-21) i686 GNU/Linux
```



```
root@sh:~/debug/memory_layout# cat test.sh
#!/bin/bash

for file in `ls *.c`;do gcc $file -o "${file/\.c/\.out}";done

ls *.out | xargs size
```

```
root@sh:~/debug/memory_layout# ll *.c
-rw-r--r-- 1 root root 45 Aug 28 00:10 global_var_init.c
-rw-r--r-- 1 root root 41 Aug 28 00:10 global_var_uninit.c
-rw-r--r-- 1 root root 28 Aug 28 00:10 main.c
-rw-r--r-- 1 root root 53 Aug 28 00:11 static_var_init.c
-rw-r--r-- 1 root root 46 Aug 28 00:16 static_var_uninit.c
```

```
root@sh:~/debug/memory_layout# bash test.sh
   text    data     bss     dec     hex filename
   1484     300       4    1788     6fc main.out

   1484     304       4    1792     700 global_var_init.out    /* init global variable stored in .data */
   1484     304       4    1792     700 static_var_init.out    /* init static variable stored in .data */

   1484     300       8    1792     700 global_var_uninit.out  /* uninit global variable stored in .bss */
   1484     300       8    1792     700 static_var_uninit.out  /* uninit static variable stored in .bss */
```

![](https://user-images.githubusercontent.com/7352479/29761999-145345da-8b9a-11e7-9cff-77509f499b20.png)


## References

1. http://www.geeksforgeeks.org/memory-layout-of-c-program/
2. https://www.youtube.com/watch?v=0jhQBQcGnuM
3. https://en.wikipedia.org/wiki/User_space
