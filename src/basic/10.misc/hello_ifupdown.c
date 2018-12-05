#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <net/if.h>
#include <net/if_dl.h>
#include <net/route.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include <signal.h>

#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wdangling-else"
#endif

/**
 * Ctrl + C Handler
 */
void handler(int sig)
{
	exit(EXIT_SUCCESS);
}

/**
 * Get all adapters names in OS X.
 */
void get_adapter_list()
{
	int mib[6];		// sysctl - param: name
	size_t oldlenp;		// sysctl - param: oldlenp
	void *oldp, *lim, *next;
	struct if_msghdr *ifm, *nextifm;
	struct ifa_msghdr *ifam;
	struct sockaddr_dl *sdl;
	// int flags;
	char name[32];		/* name of interface */

	mib[0] = CTL_NET;	// Networking
	mib[1] = PF_ROUTE;	// routing messages
	mib[2] = 0;
	mib[3] = 0;
	mib[4] = NET_RT_IFLIST;	//
	mib[5] = 0;

	if (sysctl(mib, 6, NULL, &oldlenp, NULL, 0) < 0) {
		perror("sysctl");
		exit(EXIT_FAILURE);
	}

	if ((oldp = malloc(oldlenp)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (sysctl(mib, 6, oldp, &oldlenp, NULL, 0) < 0) {
		perror("sysctl");
		exit(EXIT_FAILURE);
	}

	lim = oldp + oldlenp;
	next = oldp;

	while (next < lim) {
		ifm = (struct if_msghdr *)next;

		if (ifm->ifm_type == RTM_IFINFO) {
			sdl = (struct sockaddr_dl *)(ifm + 1);
		} else {
			perror("out of sync parsing NET_RT_IFLIST");
			exit(EXIT_FAILURE);
		}

		next += ifm->ifm_msglen;

		while (next < lim) {

			nextifm = (struct if_msghdr *)next;

			if (nextifm->ifm_type != RTM_NEWADDR)
				break;

			if (ifam == NULL)
				ifam = (struct ifa_msghdr *)nextifm;

			next += nextifm->ifm_msglen;
		}

		strncpy(name, sdl->sdl_data, sdl->sdl_nlen);
		name[sdl->sdl_nlen] = '\0';	// adapter interface name

		printf("%s\n", name);
	}

	free(oldp);
}

/**
 * Get adapter interface flags
 */
int getifflags(vname, s)
const char *vname;
int s;
{
	struct ifreq ifr;

	strncpy(ifr.ifr_name, vname, sizeof ifr.ifr_name);

	if (ioctl(s, SIOCGIFFLAGS, (caddr_t) & ifr) < 0) {
		perror("ioctl (SIOCGIFFLAGS)");
		exit(EXIT_FAILURE);
	}

	return ifr.ifr_flags;
}

/**
 * Set adapter interface flags
 */
void setifflags(vname, value)
const char *vname;
int value;
{
	struct ifreq ifr;
	int flags;
	int s;

	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	flags = getifflags(vname, s);
	strncpy(ifr.ifr_name, vname, sizeof ifr.ifr_name);

	if (value < 0) {
		value = -value;
		flags &= ~value;
	} else
		flags |= value;

	ifr.ifr_flags = flags;
	if (ioctl(s, SIOCSIFFLAGS, (caddr_t) & ifr) < 0)
		perror(vname);
}

/**
 * Get adapter up status
 */
bool get_if_up_status(vname)
const char *vname;
{
	int s;
	int flags;

	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	flags = getifflags(vname, s);
	return flags & IFF_UP;

	// if (flags & IFF_UP)
	//     printf("%s is online\n", vname);
	// else
	//     printf("%s is offline\n", vname);
}

/**
 * Disable adapter network deature
 */
void set_if_down(vname)
const char *vname;
{
	setifflags(vname, -IFF_UP);
}

/**
 * Enable adapter network deature
 */
void set_if_up(vname)
const char *vname;
{
	setifflags(vname, IFF_UP);
}

/**
 * Usage
 */
void usage(const char *pragname)
{
	printf("%s [command] [options]\n\n"
	       "[command]\n"
	       "\tlist                - list all adapters names\n"
	       "\tmonitor <interface> - monitor adapter status\n"
	       "\tup|down <interface> - enable/disable adapter network feature\n",
	       pragname);
}

/**
 * Main function
 */
int main(int argc, const char *argv[])
{
	if (argc < 2) {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	if (argc == 2 && strcmp(argv[1], "list") == 0)
		get_adapter_list();

	if (argc == 3)
		if (strcmp(argv[1], "monitor") == 0) {
			if (signal(SIGINT, handler) == SIG_ERR) {
				perror("signal");
				exit(EXIT_FAILURE);
			}

			while (get_if_up_status(argv[2])) {
				printf("[%s] is online\n", argv[2]);
				sleep(1);
			}
		} else if (strcmp(argv[1], "down") == 0) {
			// setifflags(adapter, -IFF_UP);
			set_if_down(argv[2]);
		} else if (strcmp(argv[1], "up") == 0) {
			// setifflags(adapter, IFF_UP);
			set_if_up(argv[2]);
		} else {
			usage(argv[0]);
			exit(EXIT_FAILURE);
		}

	return 0;
}

// references
// https://www.unix.com/man-page/osx/3/sysctl/
// https://developer.apple.com/documentation/kernel/if_msghdr
// https://opensource.apple.com/source/network_cmds/network_cmds-77/ifconfig.tproj/ifconfig.h
// https://stackoverflow.com/questions/5858655/linux-programmatically-up-down-an-interface-kernel
// https://github.com/uoaerg/wavemon/blob/master/iw_if.c
