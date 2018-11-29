#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

// struct passwd * getpwuid (uid_t uid)

// This function returns a pointer to a statically-allocated structure containing 
// information about the user whose user ID is uid.
// A null pointer value indicates there is no user in the data base with user ID uid.

// The passwd structure is defined in <pwd.h> as follows:

//    struct passwd {
//        char   *pw_name;       /* username */
//        char   *pw_passwd;     /* user password */
//        uid_t   pw_uid;        /* user ID */
//        gid_t   pw_gid;        /* group ID */
//        char   *pw_gecos;      /* user information */
//        char   *pw_dir;        /* home directory */
//        char   *pw_shell;      /* shell program */
//    };

// $ ./hello_getpwuid /etc/passwd
// passwd.pw_name   : root
// passwd.pw_passwd : *
// passwd.pw_gecos  : System Administrator
// passwd.pwdir     : /var/root
// passwd.pw_shell  : /bin/sh

void getpwuid_usage(const char *filename)
{
	struct stat st;
	struct passwd *pw;

	if (stat(filename, &st) != 0) {
		fprintf(stderr, "stat() failed.\n");
		exit(1);
	}

	pw = getpwuid(st.st_uid);
	if (pw == NULL) {
		fprintf(stderr, "getpwuid() failed.\n");
		exit(1);
	}

	printf("passwd.pw_name   : %s\n", pw->pw_name);
	printf("passwd.pw_passwd : %s\n", pw->pw_passwd);
	printf("passwd.pw_gecos  : %s\n", pw->pw_gecos);
	printf("passwd.pwdir     : %s\n", pw->pw_dir);
	printf("passwd.pw_shell  : %s\n", pw->pw_shell);
}

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		printf("[*] Usage: %s </path/to/file>\n", argv[0]);
		exit(1);
	}

	getpwuid_usage(argv[1]);
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Lookup-User.html
