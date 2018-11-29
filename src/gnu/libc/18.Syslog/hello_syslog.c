#include <syslog.h>

    // void openlog (const char *ident, int option, int facility)

// [ident] is an arbitrary identification string which future syslog invocations will prefix to each message.
// This is intended to identify the source of the message, and people conventionally set it to the name of
// the program that will submit the messages.

// If [ident] is NULL, or if openlog is not called, the default identification string used in Syslog messages
// will be the program name, taken from argv[0].

// options is a bit string, with the bits as defined by the following single bit masks:

    // LOG_PERROR
    // LOG_CONS
    // LOG_PID
    // LOG_NDELAY
    // LOG_ODELAY

// [facility] is the default facility code for this connection. A syslog on this connection that specifies 
// default facility causes this facility to be associated with the message. See syslog for possible values.
// A value of zero means the default, which is LOG_USER.

    // void syslog (int facility_priority, const char *format, …)
    // void closelog (void)

void syslog_usage(void)
{
	openlog("testing", LOG_CONS | LOG_PID, LOG_USER);
	syslog(LOG_INFO, "this is an information log.");
	closelog();

	// $ cat /var/log/syslog
	// Oct  3 14:57:06 lab testing[12259]: this is an information log.
}

int main(void)
{
	syslog_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/openlog.html#openlog
// https://www.gnu.org/software/libc/manual/html_node/closelog.html#closelog
// https://www.gnu.org/software/libc/manual/html_node/syslog_003b-vsyslog.html#syslog_003b-vsyslog
