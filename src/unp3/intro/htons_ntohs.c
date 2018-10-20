#include <stdio.h>
#include <netinet/in.h>

// uint16_t htons(uint16_t hostshort);
// uint16_t ntohs(uint16_t netshort);
// uint32_t htonl(uint32_t hostlong);
// uint32_t ntohl(uint32_t netlong)

// In the names of these functions,
// h stands for host,
// n stands for network,
// s stands for short,
// l stands for long.

// We should instead think of s as a 16-bit value.
// (such as a TCP or UDP port number) and l as a
// 32-bit value (such as an IPv4 address).

int
main(int argc, const char *argv[])
{
	int port = 8090;

	printf("htons(8090) = %X\n", htons(port));
	printf("ntohs(htons(8090)) = %d\n", ntohs(htons(port)));

	return 0;
}