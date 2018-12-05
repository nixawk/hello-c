#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

    // int mlock (const void *addr, size_t len)

// mlock locks a range of the calling process' virtual pages.

// The range of memory starts at address addr and is len bytes long.
// Actually, since you must lock whole pages, it is the range of pages
// that include anu part of the specified range.

// When the function returns successfully, each of those pages is backed by
// (connected to) a real frame (is marked) to stay that way. This means the
// function may cause page-ins and have to wait for them.

    // int munlock (const void *addr, size_t len)

// munlock unlocks a range of the calling process' virtual pages.
// munlock is the inverse of mlock and functions completely analogously
// to mlock, except that there is on EPERM failure.

#define BUFSIZE 512

void valid_status(int ret)
{
	switch (ret) {
	case ENOMEM:
		printf("no available address range\n");
		break;

	case EPERM:
		printf("the calling process is not superuser\n");
		break;

	case EINVAL:
		printf("mlock length is not positive\n");
		break;

	case ENOSYS:
		printf("kernel does not privide mlock capablity\n");
		break;

	default:
		printf("mlock/munlock successfully\n");
	}
}

void mlock_usage(void)
{
	char *ptr = malloc(BUFSIZE);
	int lock_ret, unlock_ret;

	lock_ret = mlock(ptr, BUFSIZE);
	unlock_ret = munlock(ptr, BUFSIZE);

	valid_status(lock_ret);
	valid_status(unlock_ret);

	free(ptr);
}

int main(void)
{
	mlock_usage();

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Functions-To-Lock-And-Unlock-Pages
