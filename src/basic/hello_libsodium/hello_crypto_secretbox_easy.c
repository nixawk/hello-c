#include <stdio.h>
#include <sodium.h>

#define MESSAGE ((const unsigned char *) "helloworld")
#define MESSAGE_LEN 10
#define CIPHERTEXT_LEN (crypto_secretbox_MACBYTES + MESSAGE_LEN)

void crypto_secretbox_easy_usage()
{
	unsigned char encrypt[CIPHERTEXT_LEN];
	unsigned char decrypt[MESSAGE_LEN];
	unsigned char key[crypto_secretbox_KEYBYTES];
	unsigned char nonce[crypto_secretbox_NONCEBYTES];
	char hex[CIPHERTEXT_LEN * 2 + 1];

	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}
	// Create a secret key using crypto_secretbox_keygen()
	crypto_secretbox_keygen(key);

	// Create a nonce using randombytes_buf(nonce, sizeof nonce);
	randombytes_buf(nonce, sizeof nonce);

	// Using crypto_secretbox_easy() to encrypt the message, and send/store
	// the resulting ciphertext along with the nonce. Unlike the key, the nonce
	// doesn't have to be secret.
	crypto_secretbox_easy(encrypt, MESSAGE, MESSAGE_LEN, nonce, key);

	sodium_bin2hex(hex, CIPHERTEXT_LEN * 2 + 1, encrypt, CIPHERTEXT_LEN);
	printf("%s\n", hex);

	// Use crypto_secretbox_open_easy to decrypt the ciphertext using the same
	// key and nonce.
	if (crypto_secretbox_open_easy
	    (decrypt, encrypt, CIPHERTEXT_LEN, nonce, key) != 0) {
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MESSAGE_LEN; i++) {
		printf("%c", decrypt[i]);
	}
	printf("\n");
}

int main(void)
{
	crypto_secretbox_easy_usage();

	return 0;
}

// reference
// https://download.libsodium.org/doc/quickstart#how-do-i-encrypt-data
// https://github.com/jedisct1/libsodium/blob/master/src/libsodium/include/sodium/crypto_secretbox.
// https://download.libsodium.org/doc/secret-key_cryptography/authenticated_encryption#example
// https://github.com/jedisct1/libsodium/blob/master/src/libsodium/crypto_secretbox/crypto_secretbox_easy.c
