#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "ts_liste.h"

extern nb_ligne = 1;
extern Col = 1;
extern fileName[50];

int semantiqueError(char *msg)
{
    printf("%s", msg);
    printf("\nFile %s, line %d, character %d: semantic error\n", fileName, nb_ligne, Col);
    displayList_Sep_MotCle();
    displayList_Cst_Idf();
    exit(EXIT_FAILURE);
}

void traitement_Fin_Routine(Stack *stack_name_Routine, Stack *stack_value, Stack *stack_type, int *nbArg)
{
    add_TYPE_Cst_Idf(top(stack_name_Routine), top(stack_type), "");
    add_CODE_Cst_Idf(top(stack_name_Routine), "ROUTINE", "");
    if (strcmp(top(stack_name_Routine), top(stack_name_Routine)) != 0)
        semantiqueError("Error: the last line of ROUTINE should be affectation with name of ROUTINE");
    /*save in ts nombre d'arguments*/
    add_VALUE_Cst_Idf(top(stack_name_Routine), top(stack_value), "");
    pop(stack_type);
    pop(stack_value);
    pop(stack_name_Routine);
    nbArg = 0;
}

void Check_Retour_Routine(const char nomVariable_Retour[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
    if (strcmp(nomVariable_Retour, top(stack_name_Routine)) != 0)
        semantiqueError("Le nom de cette variable doit etre le meme que cele de la routine");
}

void Taitement_SUITE_DEC(const char nomVariable[MAX_NAME_LENGTH], Stack *stack_name_Routine, Stack *stack_type)
{
    if (idf_exist(nomVariable, top(stack_name_Routine)))
        semantiqueError("Double declaration");
    add_SCOPE_Cst_Idf(nomVariable, top(stack_name_Routine));
    add_TYPE_Cst_Idf(nomVariable, top(stack_type), top(stack_name_Routine));
    add_CODE_Cst_Idf(nomVariable, "VARIABLE", top(stack_name_Routine));
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

void ConcatTaille(int num1, int num2, char *result, size_t result_size)
{
    const char *separator = " | ";

    // Convert integers to strings
    char str1[20]; // Adjust the size based on the expected maximum length of an integer
    char str2[20];
    sprintf(str1, "%d", num1);
    sprintf(str2, "%d", num2);

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len_sep = strlen(separator);
    size_t len_result = len1 + len_sep + len2 + 1; // +1 for  \0

    // Ensure the result buffer is large enough
    if (len_result > result_size)
    {
        fprintf(stderr, "Result buffer is too small, %zu\n", result_size);
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, separator);
    strcat(result, str2);
}

void extractIntegers_SIZE_TS(const char *sizeTS, int *firstSize, int *secondSize)
{
    // Use sscanf to extract two integers separated by '|'
    if (sscanf(sizeTS, " %d | %d", firstSize, secondSize) != 2)
    {
        // Handle error, if the format doesn't match
        printf("Error: Invalid sizeTS format!\n");
    }
}
