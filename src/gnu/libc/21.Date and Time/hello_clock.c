#include <time.h>
#include <stdio.h>

// To get a process' CPU time, you can use the clock function. This facility
// is declared in the header file time.h.

// In typical usage, you call the clock function at the beginning and end of
// the interval you want to time, subtract the values, and then divide by
// CLOCKS_PER_SEC (the number of clock ticks per second) to get processor time,

// Macro: int CLOCKS_PER_SEC

// The value of this macro is the number of clock ticks per second measured by
// the clock function. POSIX requires that this value be one million
// independent of the actual resolution.

// Data Type: clock_t

// This is the type of the value returned by the clock function. Values of type
// clock_t are numbers of clock ticks.

// Function: clock_t clock(void)

// This function returns the calling process' current CPU time. If the CPU time
// is not available or cannot be represented, clock returns the value
// (clock_t)(-1).

void foo(void)
{
	int i;

	for (i = 0; i < 10; i++) ;	// do nothing
}

void show_cpu_time(void)
{
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	/* do something you want */
	foo();

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("CPU Time: %f\n", cpu_time_used);
}

int main(void)
{
	show_cpu_time();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/CPU-Time.html#CPU-Time
