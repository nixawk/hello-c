// What is a Linked List ?

// A linked list is a set of dynamically allocated nodes, arranged in
// such a way that each node contains one value and one pointer. The
// pointer always points to the next member of the list. If the pointer
// is NULL, then it is the last node in the list.

// Linked Lists have a few advantages over arrays:

// 1. Items can be added or removed from the moddle of the list.
// 2. There is no need to define an initial size.

// Linked Lists also have a few disadvantages:

// 1. There is no "random" accesss - it is impossible to reach the nth
//    item in the array without first iterating over all items up until
//    that item. This means we have to start from the beginning of the
//    list and count how many times we advance in the list until we
//    get to the desired item.

// 2. Dynamic memory allocation and pointers are required, which
//    complicates the code and increases the risk of memory leaks and segment
//    faults.

// 3. Linked lists have a much larger overhead over arrays, since linked list
//    items are dynamically allocated (which is less efficient in memory usage)
//    and each item in the list also must store an additional pointer.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node_t;

// Iterating over a list
void print_list(node_t * head)
{
	node_t *current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

// Adding an item to the end of the list
void push_end(node_t * head, int val)
{
	node_t *current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

// Adding an item to the head of the list
void push_head(node_t ** head, int val)
{
	node_t *new_node = NULL;

	new_node = malloc(sizeof(node_t));
	new_node->val = val;
	new_node->next = *head;

	*head = new_node;
}

// Removing the head item of the list
int pop_head(node_t ** head)
{
	int retval = -1;
	node_t *next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

// Removing the last item of the list
int pop_last(node_t * head)
{
	int retval = 0;
	node_t *current = NULL;

	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	}

	/* get to the second to last node in the list */
	current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* now current points to the second to last item of the list.
	   so let's remove current->next */
	retval = current->next->val;
	free(current->next);
	current->next = NULL;

	return retval;
}

// Removing a specific item
int remove_by_index(node_t ** head, int n)
{
	int i = 0;
	int retval = -1;
	node_t *current = *head;
	node_t *temp_node = NULL;

	if (n == 0) {
		return pop_head(head);
	}

	for (i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}

int main(int argc, const char *argv[])
{
	int i;
	node_t *testnode;

	for (i = 0; i < argc; i++) {
		push_head(&testnode, atoi(argv[i]));
	}

	print_list(testnode);

	return 0;
}

// http://www.learn-c.org/en/Linked_lists
// https://www.geeksforgeeks.org/data-structures/linked-list/
