#include <unistd.h>
#include <stdio.h>

// Function: uid_t getuid (void)
// The getuid function returns the real user ID of the process.


// Function: uid_t geteuid (void)
// The geteuid function returns the effective user ID of the process.


// Function: gid_t getgid (void)
// The getgid function returns the real group ID of the process.


// Function: gid_t getegid (void)
// The getegid function returns the effective group ID of the process.

int
main(void)
{
    uid_t uid = getuid();    /* get real user ID of calling process */
    uid_t euid = geteuid();  /* get effective user ID of calling process */

    printf("getuid() = %d\n", uid);
    printf("geteuid() = %d\n", euid);

    return 0;
}