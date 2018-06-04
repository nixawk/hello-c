
// Stack is a linear data structure which follows a particular order in
// which the operations are performed. The order may be LIFO (Last In First
// Out) or FILO (First In Last Out).

// Mainly the following three basic operations are performed in the stack:

    // Push: Adds an item in the stack. If the stack is full, then it is said
    // to be an Overflow condition.

    // Pop: Removes an item from the stack. The items are popped in the
    // reversed order in which they are pushed. If the stack is empty, then
    // it is said to be an Underflow condition.

    // Peek or Top: Returns top element of stack.

    // isEmpty: Returns true if stack is empty, else false.

// There are two ways to implement a stack

    // Using Array
    // Using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A strucutre to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// function to create a stack of given capacity.
// It initialize stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;

    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int main()
{
    struct Stack *stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // printf("Top item is %d\n", stack->top);
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    // printf("Top item is %d\n", stack->top);

    return 0;
}

// https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
