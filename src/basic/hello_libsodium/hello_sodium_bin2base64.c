#include <stdio.h>
#include <sodium.h>

/*

char *sodium_bin2base64(char * const b64, const size_t b64_maxlen,
                        const unsigned char * const bin, const size_t bin_len,
                        const int variant);

The sodium_bin2base64() function encoders bin as a Base64 string. variant must
be one of:

    sodium_base64_VARIANT_ORIGINAL
    sodium_base64_VARIANT_ORIGINAL_NO_PADDING
    sodium_base64_VARIANT_URLSAFE
    sodium_base64_VARIANT_URLSAFE_NO_PADDING

None of these Base64 variants provides any form of encryption; just like hex
encoding, anyone can decode them.

Computing a correct size for b64_maxlen is not straighforward and minimum number
of bytes required to encode BIN_LEN bytes using the Base64 variant VARIANT. The
returned length includes a trailing \0 byte.

int sodium_base642bin(unsigned char * const bin, const size_t bin_maxlen,
                      const char * const b64, const size_t b64_len,
                      const char * const ignore, size_t * const bin_len,
                      const char ** const b64_end, const int variant);

The function returns 0 on success.
It returns -1 if more than bin_maxlen bytes would be required to store the
parsed string, or if the string couldn't be fully parsed, but a valid pointer
for b64_end was not provided.

*/

#ifndef BUFSIZE
#define BUFSIZE 32
#endif

void sodium_bin2base64_usage()
{
	unsigned char buf[BUFSIZE];
	char b64[sodium_base64_ENCODED_LEN
		 (BUFSIZE, sodium_base64_VARIANT_ORIGINAL)];
	unsigned char bin[BUFSIZE];

	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}

	randombytes_buf(buf, BUFSIZE);
	sodium_bin2base64(b64,
			  sodium_base64_ENCODED_LEN(BUFSIZE,
						    sodium_base64_VARIANT_ORIGINAL),
			  buf, BUFSIZE, sodium_base64_VARIANT_ORIGINAL);

	printf("%s\n", b64);
	sodium_base642bin(bin, BUFSIZE,
			  b64, sodium_base64_ENCODED_LEN(BUFSIZE,
							 sodium_base64_VARIANT_ORIGINAL),
			  NULL, NULL, NULL, sodium_base64_VARIANT_ORIGINAL);

	if (sodium_memcmp(buf, bin, BUFSIZE) == 0) {
		printf("buf == bin\n");
	}
}

int main(void)
{
	sodium_bin2base64_usage();
	return 0;
}

// reference
// https://download.libsodium.org/doc/helpers#base64-encoding-decoding
