#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void
swapNodes(struct Node **head_ref, int x, int y)
{
    struct Node *prevX = NULL, *currX = *head_ref;
    struct Node *prevY = NULL, *currY = *head_ref;
    struct Node *temp = NULL;

    if (x == y)
        return;

    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head_ref = currX;

    // Swap next pointers
    temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

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
printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int
main()
{
    struct Node *node = NULL;

    push(&node, 7);
    push(&node, 6);
    push(&node, 5);
    push(&node, 4);
    push(&node, 3);
    push(&node, 2);
    push(&node, 1);

    printf("\n Linked list before calling swapNodes() ");
    printList(node);

    swapNodes(&node, 4, 3);

    printf("\n Linked list after calling swapNodes() ");
    printList(node);

    return 0;
}