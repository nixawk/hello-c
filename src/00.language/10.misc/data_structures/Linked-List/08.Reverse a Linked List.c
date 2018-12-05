#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

static void reverse(struct Node **head_ref)
{
	struct Node *prev = NULL;
	struct Node *current = *head_ref;
	struct Node *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void push(struct Node **head_ref, int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node *node = NULL;

	push(&node, 20);
	push(&node, 4);
	push(&node, 15);
	push(&node, 85);

	printf("Given linked list\n");
	printList(node);

	reverse(&node);

	printf("\nReversed Linked list\n");
	printList(node);

	return 0;
}

// https://www.geeksforgeeks.org/reverse-a-linked-list/
