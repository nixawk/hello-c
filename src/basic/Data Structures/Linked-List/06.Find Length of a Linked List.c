#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

void
push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int
getCount(struct Node *head)
{
    int count = 0;
    struct Node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int
main()
{
    struct Node *head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    printf("count of nodes is %d\n", getCount(head));
    return 0;
}

// https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
