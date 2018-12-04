/*

typedef: typedef is used to give a new name to an already existing or even a
custom data type (like a structure). It comes in very handy at times, for 
example in a case when the name of the structure defined by you is very
long or you just need a short-hand notation of a per-existig data type.

*/
#include <stdio.h>

struct person {
	char name[256];
	int age;
};

int main(void)
{
struct person ted = { name: "Kizawa Ted", age:25 };

	printf("name: %s, age: %d\n", ted.name, ted.age);
	return 0;
}
