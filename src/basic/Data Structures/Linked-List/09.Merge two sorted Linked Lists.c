#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node*
SortedMerge(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

void
push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void
printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int
main()
{
    struct Node *a = NULL, *b = NULL;
    struct Node *result = NULL;

    push(&a, 3);
    push(&a, 4);

    push(&b, 1);
    push(&b, 2);

    printf("Before SortedMerge\n");
    printList(a);
    printList(b);
    printf("\n");

    result = SortedMerge(a, b);

    printf("After SortedMerge\n");
    printList(result);
    printf("\n");

    return 0;
}

// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
