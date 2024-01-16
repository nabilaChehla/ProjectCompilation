#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "../include/tools.h"
#include <windows.h>

void setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

void ConcatTaille(char num1[], char num2[], char *result, size_t result_size)
{
    const char *separator = " | ";

    // Convert integers to strings

    size_t len1 = strlen(num1);
    size_t len2 = strlen(num2);
    size_t len_sep = strlen(separator);
    size_t len_result = len1 + len_sep + len2 + 1; // +1 for  \0

    // Ensure the result buffer is large enough
    if (len_result > result_size)
    {
        fprintf(stderr, "Result buffer is too small, %zu\n", result_size);
        exit(EXIT_FAILURE);
    }

    strcpy(result, num1);
    strcat(result, separator);
    strcat(result, num2);
}

/*-----------------------------------------------------------------------*/
char *intToString(int number)
{
    // Determine the maximum number of digits needed
    int numDigits = snprintf(NULL, 0, "%d", number);

    // Allocate memory for the string representation
    char *result = (char *)malloc((numDigits + 1) * sizeof(char));

    // Convert the integer to a string
    snprintf(result, numDigits + 1, "%d", number);

    return result;
}
char *floatToString(float number)
{
    // Determine the maximum number of digits needed
    int numDigits = snprintf(NULL, 0, "%g", number);

    // Allocate memory for the string representation
    char *result = (char *)malloc((numDigits + 1) * sizeof(char));

    // Convert the float to a string using the %g format specifier
    snprintf(result, numDigits + 1, "%g", number);

    return result;
}

void extractIntegers_SIZE_TS(const char *sizeTS, char *firstSize, char *secondSize)
{
    // Use sscanf to extract two integers separated by '|'

    if (sscanf(sizeTS, "%s | %s", firstSize, secondSize) != 2)
    {
        // Handle error, if the format doesn't match
        printf("Error: Invalid sizeTS format!\n");
    }
}

char *extractTableName(const char *input)
{
    // Find the opening parenthesis
    const char *openParen = strchr(input, '(');

    // Check if the opening parenthesis is found
    if (openParen != NULL)
    {
        // Calculate the length of the table name
        size_t length = openParen - input;

        // Allocate memory for the table name
        char *tableName = (char *)malloc(length + 1);

        // Copy the table name into the allocated memory
        strncpy(tableName, input, length);
        tableName[length] = '\0'; // Null-terminate the string

        return tableName;
    }
    else
    {
        // Return NULL if the opening parenthesis is not found
        return NULL;
    }
}
