#include <stdio.h>

struct person {
	char name[256];
	int age;
};

void member_access(void)
{
	struct person *p;
	struct person ted = { name: "Moki Ted", age: 25 };

	p = &ted;
	printf("name: %s, age: %d\n", ted.name, ted.age);
	printf("name: %s, age: %d\n", p->name, p->age);
}

int main(void)
{
	member_access();
	return 0;
}

/* https://en.cppreference.com/w/c/language/expressions#Constants_and_literals */
