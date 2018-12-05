CC=gcc
CFLAGS=$(pkg-config --cflags libsodium)
DFLAGS=-lsodium# $(pkg-config --libs libsodium)    # -lsodium

define compile
	$(CC) -o $(basename $(1) .c) $(CFLAGS) $(DFLAGS) $(1)
endef

default:
	$(call compile,hello_sodium_init.c)
	$(call compile,hello_randombytes_random.c)
	$(call compile,hello_randombytes_uniform.c)
	$(call compile,hello_randombytes_buf.c)
	$(call compile,hello_crypto_generichash.c)
	$(call compile,hello_crypto_secretbox_easy.c)
	$(call compile,hello_sodium_bin2hex.c)
	$(call compile,hello_sodium_bin2base64.c)
	$(call compile,hello_sodium_add.c)
	$(call compile,hello_sodium_compare.c)
	$(call compile,hello_sodium_is_zero.c)
	$(call compile,hello_sodium_stackzero.c)
	$(call compile,hello_sodium_pad.c)
	$(call compile,hello_sodium_memzero.c)

clean:
	rm -rf hello_sodium_init \
		hello_randombytes_random \
		hello_randombytes_uniform \
		hello_randombytes_buf \
		hello_crypto_generichash \
		hello_crypto_secretbox_easy \
		hello_sodium_bin2hex \
		hello_sodium_bin2base64 \
		hello_sodium_add \
		hello_sodium_compare \
		hello_sodium_is_zero \
		hello_sodium_stackzero \
		hello_sodium_pad \
		hello_sodium_memzero

# https://www.gnu.org/software/make/manual/make.html#Call-Function
# https://www.gnu.org/software/make/manual/html_node/Suffix-Rules.html
# ftp://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_8.html
# https://stackoverflow.com/questions/13995906/get-filename-without-extension-within-makefile