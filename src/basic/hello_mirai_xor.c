/*

How to encrypt/decrypt mirai string ?

$ gcc mirai_tool_enc.c -o mirai_tool_enc

$ ./mirai_tool_enc
Usage: ./mirai_tool_enc <encrypt | decrypt> <data>

$ ./mirai_tool_enc encrypt www.google.com
encrypt 15 bytes of data...
\x55\x55\x55\x0C\x45\x4D\x4D\x45\x4E\x47\x0C\x41\x4D\x4F\x22

$ ./mirai_tool_enc decrypt 5555550C454D4D454E470C414D4F22
decrypt 15 bytes of data...
www.google.com

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>


static uint32_t ENCRYPT_KEY = 0xdeadbeef;
static uint32_t DECRYPT_KEY = 0xefbeadde;  // reverse ENCRYPT_KEY


typedef struct {
    uint8_t k1;
    uint8_t k2;
    uint8_t k3;
    uint8_t k4;
} xorkey_t;


typedef union {
    uint32_t key;
    xorkey_t st; 
} xorkey;


/* xor algorithm - encrypt/decrypt */
void*
xor(void *buf, int len, int key)
{
    xorkey xk;
    xk.key = key;

    unsigned char *out = (unsigned char *)strndup(buf, len);

    int i;
    for (i = 0; i < len; i++)
    {
        char tmp = ((char *)buf)[i];
        tmp ^= (xk.st.k1 & 0xff);
        tmp ^= (xk.st.k2 & 0xff);
        tmp ^= (xk.st.k3 & 0xff);
        tmp ^= (xk.st.k4 & 0xff);

        out[i] = tmp;
    }

    return out;
}


int
main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <encrypt | decrypt> <data>\n", argv[0]);
        return 0;
    }

    void *data;
    int len, i, c;

    if (strcmp(argv[1], "encrypt") == 0)
    {
        len = strlen(argv[2]) + 1;
        printf("encrypt %d bytes of data...\n", len);

        data = xor(argv[2], len, ENCRYPT_KEY);
        for (i = 0; i < len; i++)
            printf("\\x%02X", ((unsigned char *)data)[i]);

        printf("\n");
    }
    else if (strcmp(argv[1], "decrypt") == 0)
    {
        len = strlen(argv[2]);
        printf("decrypt %d bytes of data...\n", len / 2);

        for (i=0; i < len; i+=2)
        {
            sscanf(&argv[2][i], "%2x", &c);
            data = xor(&c, 1, DECRYPT_KEY);
            printf("%c", ((unsigned char *)data)[0]);
        }
    }
    else
    {
        printf("Unknown data type `%s`!\n", argv[1]);
        return -1;
    }

    return 1;
}


// https://github.com/jgamblin/Mirai-Source-Code/blob/master/mirai/tools/enc.c