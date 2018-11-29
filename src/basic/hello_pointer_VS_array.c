#include <stdio.h>

/*
Most of the time, pointer and array accesses can be treated as acting the same, the major exceptions being:

    - sizeof
      - sizeof(array) returns the amount of memory used by all elements in array.
      - sizeof(pointer) only returns the amount of memory used by the pointer variable itself.
    - &
      - &array is an alias for &array[0] and returns the address of the first element in array
      - &pointer retutns the address of pointer
    - string initialization
      - char array[] = "abc" (sets the first four elements in array to 'a', 'b', 'c' and '\0')
      - char *pointer = "abc" (sets pointer to the address of the "abc" string, which  may be stored in read-only memory and unchangeable)
*/

/* sizeof */
void sizeof_demo(void)
{
	int ary[3] = { 1, 2, 3 };
	int *ptr = ary;

	printf("%lu\n", sizeof(ary));	/* returns the amount of memory used by all elements in array */
	printf("%lu\n", sizeof(ptr));	/* returns the amount of memory used by the pointer variable itself */
}

/* & */
void opaddr_demo(void)
{
	int ary[3] = { 1, 2, 3 };
	int *ptr = ary;

	printf("%p\n", &ary);	/* return the address of the first element */
	printf("%p\n", ptr);	/* point to the address of the array */
	printf("%p\n", &ptr);	/* point to the address of the pointer */

}

/* string initialization */
void init_demo(void)
{
	char ary[] = "abc";	/* changeable */
	char *ptr = "abc";	/* unchangeable */

	ary[0] = 'A';
	ptr[0] = 'A';		/* exception here */
}

int main(int argc, const char *argv[])
{
	sizeof_demo();
	opaddr_demo();
	init_demo();
	return 0;
}
