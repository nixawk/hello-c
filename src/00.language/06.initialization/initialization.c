/*
 * A declaration of an object may provide its initial value through the process
 * known as initialization.
 *
 * For each declarator, the initializer, if not omitted, may be one of the
 * following:
 *
 * 	= expression         (1)
 * 	={initializer-list}  (2)
 *
 */

int main(void)
{
	int n = 1234;
	struct {
		char name[256];
		int age;
	} ted = { name: "Moki Ted", age:25 };

	return 0;
}

/* https://en.cppreference.com/w/c/language/initialization */
/* https://en.cppreference.com/w/c/language/scalar_initialization */
