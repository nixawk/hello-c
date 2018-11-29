// Automatic Storage Class
// A variable defined within a function or block with **auto** specifier
// belongs to automatic storage class. All variables defined within a
// function or block by default belong to automatic storage class if
// no storage class is mentioned. Variables having automatic storage
// class are local to the block which they are defined in, and get
// destroyed on exit from the block.

#include <stdio.h>

void storage_class_auto(void)
{
	auto int i = 1;
	{
		auto int i = 2;
		{
			auto int i = 3;
			{
				auto int i = 4;
				printf("i = %d\n", i);
			}
			printf("i = %d\n", i);
		}
		printf("i = %d\n", i);
	}
	printf("i = %d\n", i);
}

int main(void)
{
	storage_class_auto();
	return 0;
}

// http://cs-fundamentals.com/c-programming/storage-classes-in-c-and-storage-class-specifiers.php
