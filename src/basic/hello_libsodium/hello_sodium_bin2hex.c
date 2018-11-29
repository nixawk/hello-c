#include <stdio.h>
#include <sodium.h>

/*

char *sodium_bin2hex(char * const hex, const size_t hex_maxlen,
                     const unsigned char * const bin, const size_t bin_len);

The sodium_bin2hex() function converts bin_len bytes stored at bin into a
hexadecimal string.

The string is stored into hex and includes a nul byte (\0) terminator.

hex_maxlen is the maximum number of bytes that the function is allowed to
write starting at hex. It must be at least bin_len * 2 + 1 bytes.

int sodium_hex2bin(unsigned char * const bin, const size_t bin_maxlen,
                   const char * const hex, const size_t hex_len,
                   const char * const ignore, size_t * const bin_len,
                   const char ** const hex_end);

The sodium_hex2bin() function parses a hexadecimal string hex and converts it
to a byte sequence.

hex does not have to be nul terminated, as the number of characters to parse
is suppiled via the hex_len parameter.

*/

#define MESSAGE ((const unsigned char *) "hello world")
#define MESSAGE_LEN 11

void sodium_bin2hex_usage()
{
	char hex[MESSAGE_LEN * 2 + 1];
	unsigned char bin[MESSAGE_LEN];

	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}

	sodium_bin2hex(hex, MESSAGE_LEN * 2 + 1, MESSAGE, MESSAGE_LEN);
	printf("%s\n", hex);
	sodium_hex2bin(bin, MESSAGE_LEN, hex, MESSAGE_LEN * 2 + 1, NULL, NULL,
		       NULL);

	if (sodium_memcmp(MESSAGE, bin, MESSAGE_LEN) == 0) {
		printf("MESSAGE == sodium_hex2bin(sodium_bin2hex(MESSAGE))\n");
	}
}

int main(void)
{
	sodium_bin2hex_usage();
	return 0;
}

// reference
// https://download.libsodium.org/doc/helpers
