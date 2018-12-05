/*

// http://www.geeksforgeeks.org/difference-int-main-int-mainvoid/

#include <stdio.h>
int main()            // int main() can be called with any number of arguments, 
{
    static int i = 5;
    if (--i){
        printf("%d ", i);
        main(10);    // It will be compiled, and executed.
    }
}

*/

#include <stdio.h>
int main(void)			// int main(void) can only be called without any argument.
{
	static int i = 5;
	if (--i) {
		printf("%d ", i);
		main(10);	// compilation error.
	}
}
