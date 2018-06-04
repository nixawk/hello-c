// Unlike Arrays, Linked Lists, Stack and queues, which are linear
// data structures, trees are hierarchical data structures.

// The topmost node is called root of the tree. The elements that
// are directly under an element are called its children. The
// element directly above something is called its parent.

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    /*create root*/
    struct node *root = newNode(1);

    /* following is the tree after above statement 

        1
      /   \
     NULL  NULL  
    */

    root->left = newNode(2);
    root->right = newNode(3);

    /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
    */

    root->left->left = newNode(4);
    /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
    4    NULL  NULL  NULL
    /  \
    NULL NULL
    */


    return 0;

}

// https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
