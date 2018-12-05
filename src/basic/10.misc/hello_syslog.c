#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

void hello_daemon()
{
	if (daemon(1, 0) == -1) {
		perror("daemon()");
		exit(EXIT_FAILURE);
	}
}

void hello_syslog()
{
	const char *ident = "hello_syslog";	// program name

	openlog(ident, LOG_PID, LOG_USER);
	syslog(LOG_INFO, "%s - %m", "Just for fun");
	closelog();
}

int main(void)
{
	hello_daemon();
	hello_syslog();

	exit(EXIT_SUCCESS);
}
