// Linked List vs Array

// Both Arrays and Linked List can be used to store linear data of similar types,
// but they both some advantages and disadvantages over each other.

// Following are the points in favour of Linked Lists.

// (1) The size of the arrays is fixed: So we must know the upper limit on the
//     number of elements in advance. Also, generally, the allocated memory is
//     equal to the upper limit irrespective of the usage, and in partical uses,
//     upper limit is rarerly reached.

// (2) Inserting a new element in an array of elements is expensive, because
//     room has to be created for the new elements and to create room existing
//     elements have to shifted.

// Linked List provides following two advantages over arrays

// 1) Dynamic size
// 2) Ease of insertion/deletion

// Linked List have following drawbacks

// 1) Random access is not allowed. We have to access elements sequentially
//    starting from the first node. So we cannot do binary search with linked list.
// 2) Extra memory space for a pointer is required with each element of the list.
// 3) Arrays have better cache locality that can make a pretty big difference in
//    performance

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node * next;
} node_t;


void
linked_list(void)
{
    node_t node1st;
    node_t node2nd;
    node_t node3rd;

    node_t * tmpnode;

    node3rd.val = 3;
    node3rd.next = NULL;

    node2nd.val = 2;
    node2nd.next = &node3rd;

    node1st.val = 1;
    node1st.next = &node2nd;

    // Access Order
    // 1st -> 2nd -> 3rd

    tmpnode = &node1st;
    while (tmpnode != NULL)
    {
        printf("%d\n", tmpnode->val);
        tmpnode = tmpnode->next;
    }

}

int
main(void)
{
    linked_list();
    return 0;
}

// https://www.geeksforgeeks.org/linked-list-vs-array/