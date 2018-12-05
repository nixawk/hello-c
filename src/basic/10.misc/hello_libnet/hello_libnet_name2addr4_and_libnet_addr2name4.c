#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <libnet.h>

/*

$ gcc -Wall hello_libnet_name2addr4_and_libnet_addr2name4.c `libnet-config --libs`

$ sudo ./a.out 
[*] libnet_addr2name4: [feffffff] -> [255.255.255.254]
[*] libnet_name2addr4: ["255.255.255.254"] -> [255.255.255.254]

*/

void hello_libnet_addr2name4(u_int32_t in)
{
	libnet_t *plibnet_t;
	char errbuf[LIBNET_ERRBUF_SIZE];

	plibnet_t = libnet_init(LIBNET_RAW4, NULL, errbuf);
	if (plibnet_t == NULL) {
		fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
		exit(EXIT_FAILURE);
	}

	printf("[*] libnet_addr2name4: [%x] -> [%s]\n",
	       in, libnet_addr2name4(in, LIBNET_DONT_RESOLVE)
	    );

	libnet_destroy(plibnet_t);
}

void hello_libnet_name2addr4(char *ip_addr_str)
{
	libnet_t *plibnet_t;
	char errbuf[LIBNET_ERRBUF_SIZE];
	u_int32_t ip_addr;
	u_int8_t *ip_addr_p;

	plibnet_t = libnet_init(LIBNET_RAW4, NULL, errbuf);
	if (plibnet_t == NULL) {
		fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
		exit(EXIT_FAILURE);
	}

	ip_addr =
	    libnet_name2addr4(plibnet_t, ip_addr_str, LIBNET_DONT_RESOLVE);
	if (ip_addr != -1) {
		ip_addr_p = (u_int8_t *) (&ip_addr);
		printf("[*] libnet_name2addr4: [\"%s\"] -> [%d.%d.%d.%d]\n",
		       ip_addr_str,
		       ip_addr_p[0], ip_addr_p[1], ip_addr_p[2], ip_addr_p[3]
		    );
	} else {
		fprintf(stderr, "Error converting IP address.\n");
	}

	libnet_destroy(plibnet_t);
}

int main(void)
{
	hello_libnet_addr2name4(0xfeffffff);
	hello_libnet_name2addr4("255.255.255.254");
	return 0;
}

// references
// http://libnet.sourceforge.net/libnet.html
// https://repolinux.wordpress.com/2011/09/18/libnet-1-1-tutorial/
// https://github.com/sam-github/libnet/blob/master/libnet/include/libnet/libnet-macros.h#L49
// https://github.com/sam-github/libnet/blob/master/libnet/src/libnet_resolve.c#L44
// https://github.com/sam-github/libnet/blob/master/libnet/src/libnet_resolve.c#L88
