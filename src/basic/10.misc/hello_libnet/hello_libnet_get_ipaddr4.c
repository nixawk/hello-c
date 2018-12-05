#include <stdio.h>
#include <stdlib.h>
#include <libnet.h>

// gcc -Wall hello_libnet_get_ipaddr4.c `libnet-config --libs`

void get_ip_address(void)
{
	libnet_t *pl;
	char errbuf[LIBNET_ERRBUF_SIZE];
	uint32_t ip_addr;

	pl = libnet_init(LIBNET_RAW4, NULL, errbuf);
	if (pl == NULL) {
		fprintf(stderr, "linbet_init() failed - %s\n", errbuf);
		exit(EXIT_FAILURE);
	}

	ip_addr = libnet_get_ipaddr4(pl);

	printf("[IP]: %s\n", libnet_addr2name4(ip_addr, LIBNET_DONT_RESOLVE)
	    );

	libnet_destroy(pl);
}

void get_mac_address(void)
{
	libnet_t *pl;
	char errbuf[LIBNET_ERRBUF_SIZE];
	struct libnet_ether_addr *mac_addr;

	pl = libnet_init(LIBNET_RAW4, NULL, errbuf);
	if (pl == NULL) {
		fprintf(stderr, "linbet_init() failed - %s\n", errbuf);
		exit(EXIT_FAILURE);
	}

	mac_addr = libnet_get_hwaddr(pl);
	if (mac_addr != NULL) {
		printf("[MAC]: %02X:%02X:%02X:%02X:%02X:%02X\n",
		       mac_addr->ether_addr_octet[0],
		       mac_addr->ether_addr_octet[1],
		       mac_addr->ether_addr_octet[2],
		       mac_addr->ether_addr_octet[3],
		       mac_addr->ether_addr_octet[4],
		       mac_addr->ether_addr_octet[5]
		    );
	}
	libnet_destroy(pl);
}

int main(void)
{
	get_ip_address();
	get_mac_address();
	return 0;
}

// references
// http://libnet.sourceforge.net/libnet.html
// https://repolinux.wordpress.com/2011/09/18/libnet-1-1-tutorial/
// https://bbs.archlinux.org/viewtopic.php?id=75109
// https://github.com/sam-github/libnet/blob/master/libnet/include/libnet/libnet-macros.h
