#include <sys/times.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The times function returns information about a process' consumption of
// processor time in a struct tms object, in addition to the process' CPU
// time. See Time Basics. You should include the header file sys/times.h
// to use this facility.

// Data Type: struct tms
// The tms structure is used to return information about process times.
// It contains at least the following members:

    // clock_t tms_utime - This is the total processor time the calling
    // process has used in executing the instructions of its program.

    // clock_t tms_stime - This is the processor time the system has used
    // on behalf of the calling process.

    // clock_t tms_cutime - This is the sum of the tms_utime values and
    // the tms_cutime values of all terminated child processes of the
    // calling process, whose status has been reported to the parent
    // process by wait or waitpid; In other words, it represents the total
    // processor time used in executing the instructions of all the terminated
    // child processes of the calling process, excluding child processes
    // which have not yet been reported by wait or waitpid.

    // clock_t tms_cstime
    // This is similar to tms_cutime, but represents the total processor
    // time the system has used on behalf of all the terminated child
    // processes of the calling process.

// Macro: int CLK_TCK
// This is an obsolete name for the number of clock ticks per second.

//Function: clock_t times (struct tms *buffer)
// The times function stores the processor time information for the calling
// process in buffer.

// The return value is the number of clock ticks since an arbitrary point
// in the past, e.g. since system start-up times returns (clock_t)(-1) to
// indicate failure.

void start_clock(void);
void end_clock(char *msg);
static clock_t st_time;
static clock_t en_time;
static struct tms st_cpu;
static struct tms en_cpu;

void start_clock(void)
{
	st_time = times(&st_cpu);
}

void end_clock(char *msg)
{
	en_time = times(&en_cpu);

	fputs(msg, stdout);
	printf("Real Time: %jd, User Time: %jd, System Time: %jd\n",
	       (intmax_t) (en_time - st_time),
	       (intmax_t) (en_cpu.tms_utime - st_cpu.tms_utime),
	       (intmax_t) (en_cpu.tms_stime - st_cpu.tms_stime));
}

void wait_foo(void)
{
	int seconds = 5;
	printf("sleeping %d ...\n", seconds);
	sleep(seconds);
}

int main(void)
{
	start_clock();
	wait_foo();
	end_clock("What's CPU and Processs times ?\n");

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Processor-Time.html#Processor-Time
// http://pubs.opengroup.org/onlinepubs/009695399/functions/times.html
