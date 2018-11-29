#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <libnet.h>

// sudo apt-get install libnet1-dev
// gcc -Wall hello_libnet_init.c `libnet-config --libs`

void hello_libnet_init(const char *device)
{
	// device: a device name or IP address
	libnet_t *l;		/* the libnet context */
	char errbuf[LIBNET_ERRBUF_SIZE];

	l = libnet_init(LIBNET_RAW4, device, errbuf);
	if (l == NULL) {
		fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
		exit(EXIT_FAILURE);
	}
	libnet_destroy(l);
}

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		printf("[*] Usage: %s <device>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	// hello_libnet_init(NULL);
	hello_libnet_init(argv[1]);

	exit(EXIT_SUCCESS);
}

// references
// http://libnet.sourceforge.net/libnet.html
// https://repolinux.wordpress.com/2011/09/18/libnet-1-1-tutorial/
// https://bbs.archlinux.org/viewtopic.php?id=75109
// https://github.com/sam-github/libnet/blob/master/libnet/include/libnet/libnet-macros.h
