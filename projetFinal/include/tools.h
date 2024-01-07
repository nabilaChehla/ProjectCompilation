#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50
#define MAX_CODE_LENGTH 50
#define MAX_VAL_LENGTH 50
#define INITIAL_CAPACITY 50
#define MAX_STRING_SIZE 50
#define MAX_SCOPE_LENGTH 50

#define MAX_STRING_SIZE 50

typedef struct Node
{
    char data[MAX_STRING_SIZE];
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void push(Stack *stack, const char *value);
Stack *initializeStack();
void pop(Stack *stack);
const char *top(Stack *stack);
int isEmpty(const Stack *stack);
void freeStack(Stack *stack);
void ConcatTaille(char num1[], char num2[], char *result, size_t result_size);
char *intToString(int number);
char *floatToString(float number);
void extractIntegers_SIZE_TS(const char *sizeTS, char *firstSize, char *secondSize);
char *extractTableName(const char *input);
#endif // TOOLS_H
