#define _GNU_SOURCE

#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

// int uname(struct utsname *name);

// On success, 0 is returned. On error, -1 is returned, and errno is set.

void uname_usage(void)
{
	struct utsname utsname;
	int ret;

	ret = uname(&utsname);
	if (ret != (int)0) {	/* Call failed */
		perror("uname()");
		exit(EXIT_FAILURE);
	} else {
		printf("utsname.sysname: %s\n", utsname.sysname);
		printf("utsname.nodename: %s\n", utsname.nodename);
		printf("utsname.release: %s\n", utsname.release);
		printf("utsname.version: %s\n", utsname.version);
		printf("utsname.machine: %s\n", utsname.machine);

#ifdef _GNU_SOURCE
		printf("utsname.domainname: %s\n", utsname.domainname);
#endif
	}
}

int main(void)
{
	uname_usage();
	return 0;
}

/*

$ ./a.out 
utsname.sysname: Linux
utsname.nodename: lab
utsname.release: 4.6.0-kali1-686-pae
utsname.version: #1 SMP Debian 4.6.4-1kali1 (2016-07-21)
utsname.machine: i686
utsname.domainname: (none)
*/

// http://man7.org/linux/man-pages/man2/uname.2.html
