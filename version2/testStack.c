#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data[100];
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *initializeStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

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

    // Get the top element
    const char *topValue = stack->top->data;

    // Remove the top element
    pop(stack);

    // Return the top element
    return topValue;
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

int main()
{
    Stack *myStack = initializeStack();

    push(myStack, "Hello");
    push(myStack, "World");
    push(myStack, "!");

    printf("Top element: %s\n", top(myStack));
    // Print the remaining elements
    while (!isEmpty(myStack))
    {
        printf("Popped element: %s\n", top(myStack));
    }

    freeStack(myStack);

    return 0;
}
