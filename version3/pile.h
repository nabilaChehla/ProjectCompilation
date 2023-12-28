#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STRING_SIZE 50

//----------------------------------------------------------//

typedef struct Node
{
    char data[MAX_STRING_SIZE];
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void push(Stack *stack, const char *value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->data, value, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0'; // Ensure null-termination
    newNode->next = stack->top;
    stack->top = newNode;
}

Stack *initializeStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    push(stack, "");
    return stack;
}

void pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

const char *top(Stack *stack)
{
    if (stack->top == NULL)
    {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

int isEmpty(const Stack *stack)
{
    return stack->top == NULL;
}

void freeStack(Stack *stack)
{
    while (stack->top != NULL)
    {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}
