/*

typedef: typedef is used to give a new name to an already existing or even a custom data type (like a structure).
It comes in very handy at times, for example in a case when the name of the structure defined by you is very
long or you just need a short-hand notation of a per-existig data type.

*/
#include <stdio.h>

typedef unsigned char u_char;
typedef u_char *bytepointer;

int main(void)
{
	bytepointer s = "helloworld";
	printf("%s\n", s);

	return 0;
}
