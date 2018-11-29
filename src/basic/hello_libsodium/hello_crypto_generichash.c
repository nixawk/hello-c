#include <stdio.h>
#include <sodium.h>

/*

$ ./hello_crypto_generichash
3D C7 92 5E 13 E4 C5 F0 F8 75 6A F2 CC 71 D5 62 4B 58 83 3B B9 2F A9 89 C3 E8 7D 73 4E E5 A6 00
CB CA 67 CF 7C 47 D0 A9 59 01 12 0B 1C 37 93 1C DC 1F F9 02 B2 62 4D A0 08 61 80 44 BB 56 80 DE
61 89 CD 70 09 DD 9A 1E 16 81 6D 3F 24 91 29 4D A5 31 06 AB 08 4E 5E 69 CA 60 AA 22 05 77 D9 1E

*/

/*

int crypto_generichash(unsigned char *out, size_t outlen,
                       const unsigned char *in, unsigned long long inlen,
                       const unsigned char *key, size_t keylen);

The crypto_generichash() function puts a fingerprint of the message in whose
length is inlen bytes into out. The output size can be chosen by the application.

The minimum recommended output size is crypto_generichash_BYTES. This size makes
it practically impossible for two messages to produce the same application.

    crypto_generichash_BYTES
    crypto_generichash_BYTES_MIN
    crypto_generichash_BYTES_MAX
    crypto_generichash_KEYBYTES
    crypto_generichash_KEYBYTES_MIN
    crypto_generichash_KEYBYTES_MAX

*/

#define MESSAGE_PART1 ((const unsigned char *) "Arbitrary data to hash")

#define MESSAGE_PART2 ((const unsigned char *) "is longer than expected")

#define MESSAGE_PART1_LEN 22

#define MESSAGE_PART2_LEN 23

/* Single-part example without a key */
void crypto_generichash_usage1()
{
	unsigned char hash[crypto_generichash_BYTES];
	char hex[crypto_generichash_BYTES * 2 + 1];

	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}

	crypto_generichash(hash, sizeof hash,
			   MESSAGE_PART1, MESSAGE_PART1_LEN, NULL, 0);

	sodium_bin2hex(hex, crypto_generichash_BYTES * 2 + 1, hash,
		       sizeof hash);
	printf("%s\n", hex);

}

/* Single-part example with a key*/
void crypto_generichash_usage2()
{
	unsigned char hash[crypto_generichash_BYTES];
	unsigned char key[crypto_generichash_KEYBYTES];
	char hex[crypto_generichash_BYTES];

	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}

	crypto_generichash(hash, sizeof hash,
			   MESSAGE_PART1, MESSAGE_PART1_LEN, key, sizeof key);

	sodium_bin2hex(hex, crypto_generichash_BYTES * 2 + 1, hash,
		       sizeof hash);
	printf("%s\n", hex);
}

/* Multi-part example with a key */
void crypto_generichash_usage3()
{
	unsigned char hash[crypto_generichash_BYTES];
	unsigned char key[crypto_generichash_KEYBYTES];
	crypto_generichash_state state;
	char hex[crypto_generichash_BYTES];

	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}
	// randombytes_buf(key, sizeof key);

	// The crypto_generichash_keygen() function creates a key k of the
	// recommended length crypto_generichash_KEYBYTES

	crypto_generichash_keygen(key);

	crypto_generichash_init(&state, key, sizeof key, sizeof hash);
	crypto_generichash_update(&state, MESSAGE_PART1, MESSAGE_PART1_LEN);
	crypto_generichash_update(&state, MESSAGE_PART2, MESSAGE_PART2_LEN);
	crypto_generichash_final(&state, hash, sizeof hash);

	sodium_bin2hex(hex, crypto_generichash_BYTES * 2 + 1, hash,
		       sizeof hash);
	printf("%s\n", hex);
}

int main(void)
{
	crypto_generichash_usage1();
	crypto_generichash_usage2();
	crypto_generichash_usage3();

	return 0;
}

// reference
// https://download.libsodium.org/doc/hashing/generic_hashing
// https://download.libsodium.org/doc/hashing/generic_hashing#multi-part-example-with-a-key
