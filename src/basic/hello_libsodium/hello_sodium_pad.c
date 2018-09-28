#include <sodium.h>


void
sodium_pad_usage(void)
{
    unsigned char buf[100];
    size_t buf_unpadded_len = 10;
    size_t buf_padded_len;
    size_t block_size = 16;

    if (sodium_init() < 0)
    {
        exit(EXIT_FAILURE);
    }

    /* round the length of the buffer to a multiple of `block_size` by appending
     * padding data and put the new, total length into `buf_padded_len` */
    if (sodium_pad(&buf_padded_len, buf, buf_unpadded_len, block_size, sizeof buf) != 0)
    {
        /* overflow ! buf[] is not large enough */
        exit(EXIT_FAILURE);
    }
    printf("sodium_pad successfully !\n");

    /* compute the original, unpadded length */
    if (sodium_unpad(&buf_unpadded_len, buf, buf_padded_len, block_size) != 0)
    {
        /* incorrect padding */
        exit(EXIT_FAILURE);
    }
    printf("sodium_unpad successfully !\n");
}


int
main(void)
{
    sodium_pad_usage();
    return 0;
}

// reference
// https://download.libsodium.org/doc/padding