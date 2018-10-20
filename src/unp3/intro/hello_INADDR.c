#include <stdio.h>
#include <netinet/in.h>


int
main(int argc, const char *argv[])
{
    // #define INADDR_ANY      (u_int32_t)0x00000000
    // #define INADDR_BROADCAST    (u_int32_t)0xffffffff   /* must be masked */
    // #define INADDR_LOOPBACK     (u_int32_t)0x7f000001
    // #define INADDR_NONE     0xffffffff      /* -1 return */
    // #define INADDR_UNSPEC_GROUP (u_int32_t)0xe0000000   /* 224.0.0.0 */
    // #define INADDR_ALLHOSTS_GROUP   (u_int32_t)0xe0000001   /* 224.0.0.1 */
    // #define INADDR_ALLRTRS_GROUP    (u_int32_t)0xe0000002   /* 224.0.0.2 */
    // #define INADDR_ALLRPTS_GROUP    (u_int32_t)0xe0000016   /* 224.0.0.22, IGMPv3 */
    // #define INADDR_CARP_GROUP   (u_int32_t)0xe0000012   /* 224.0.0.18 */
    // #define INADDR_PFSYNC_GROUP (u_int32_t)0xe00000f0   /* 224.0.0.240 */
    // #define INADDR_ALLMDNS_GROUP    (u_int32_t)0xe00000fb   /* 224.0.0.251 */
    // #define INADDR_MAX_LOCAL_GROUP  (u_int32_t)0xe00000ff   /* 224.0.0.255 */

    printf("INADDR_ANY = %x\n", INADDR_ANY);
    printf("INADDR_BROADCAST = %x\n", INADDR_BROADCAST);
    printf("INADDR_LOOPBACK = %x\n", INADDR_LOOPBACK);
    printf("INADDR_NONE = %x\n", INADDR_NONE);
    printf("INADDR_UNSPEC_GROUP = %x\n", INADDR_UNSPEC_GROUP);
    printf("INADDR_ALLHOSTS_GROUP = %x\n", INADDR_ALLHOSTS_GROUP);
    printf("INADDR_ALLRTRS_GROUP = %x\n", INADDR_ALLRTRS_GROUP);
    printf("INADDR_ALLRPTS_GROUP = %x\n", INADDR_ALLRPTS_GROUP);
    printf("INADDR_CARP_GROUP = %x\n", INADDR_CARP_GROUP);
    printf("INADDR_PFSYNC_GROUP = %x\n", INADDR_PFSYNC_GROUP);
    printf("INADDR_ALLMDNS_GROUP = %x\n", INADDR_ALLMDNS_GROUP);
    printf("INADDR_MAX_LOCAL_GROUP = %x\n", INADDR_MAX_LOCAL_GROUP);

    return 0;
}
