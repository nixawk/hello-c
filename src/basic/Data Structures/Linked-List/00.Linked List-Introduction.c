// Linked List Intoduction

// Like Arrays, Linked List is a linear data structure. Unlike arrays,
// linked list elements are not stored at contiguous location; the
// elements are linked using pointers.

// Why Linked List ?

// Arrays can be used to store linear data of similar types, but arrays
// have following limitations.

// 1). The size of the arrays is fixed: So we must know the upper limit
//     on the number of elements in advance. Also, generally, the allocated
//     memory is equal to the upper limit irrespective of the usage.

// 2). Inserting a new element in an array of elements is expensive,
//     because room has to be created for the new elements and to create
//     room existing elements have to shifted.

// Advantages over arrays

// 1) Dynamic size
// 2) Ease of insertion/deletion

// Drawbacks:

// 1) Random access is not allowed. We have to access elements sequentially
//    starting from the first node. So we cannot do binary search with linked lists.

// 2) Extra memory space for a pointer is required with each element of the list.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void dir(const char *path)
{
	DIR *dp = NULL;
	struct dirent *dt = NULL;

	dp = opendir(path);
	if (dp == NULL) {
		printf("failed to opendir\n");
		exit(EXIT_FAILURE);
	}

	while ((dt = readdir(dp)) != NULL) {
		if (strcmp(dt->d_name, ".") != 0 &&
		    strcmp(dt->d_name, "..") != 0) {
			printf("%s\n", dt->d_name);
		}

	}

	closedir(dp);
}

int main(int argc, const char *argv[])
{
	int i;

	if (argc < 2) {
		printf("Usage: %s </path/to/dir/> ...\n", argv[0]);
		return -1;
	}

	for (i = 1; i < argc; i++) {
		dir(argv[i]);
	}
}

// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
