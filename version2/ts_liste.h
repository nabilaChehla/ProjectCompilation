#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50
#define MAX_CODE_LENGTH 50
#define MAX_VAL_LENGTH 50
#define INITIAL_CAPACITY 50
#define MAX_STRING_SIZE 50

typedef struct elt_Cst_Idf_node
{
  char name[MAX_NAME_LENGTH];
  char type[MAX_TYPE_LENGTH];
  char val[MAX_VAL_LENGTH];
  char code[MAX_CODE_LENGTH];
  struct elt_Cst_Idf_node *next;
} elt_Cst_Idf_node;

typedef struct elt_Sep_MotCle_node
{
  char name[MAX_NAME_LENGTH];
  char code[MAX_CODE_LENGTH];
  struct elt_Sep_MotCle_node *next;
} elt_Sep_MotCle_node;

typedef struct list_Cst_Idf
{
  elt_Cst_Idf_node *head;
} list_Cst_Idf;

typedef struct list_Sep_MotCle
{
  elt_Sep_MotCle_node *head;
} list_Sep_MotCle;

list_Cst_Idf *L_Cst_Idf;
list_Sep_MotCle *L_Sep_MotCle;

elt_Cst_Idf_node *createnode_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char code[MAX_CODE_LENGTH], const char val[MAX_VAL_LENGTH])
{
  elt_Cst_Idf_node *newNode = (elt_Cst_Idf_node *)malloc(sizeof(elt_Cst_Idf_node));
  if (!newNode)
  {
    return NULL;
  }
  strcpy(newNode->name, name);
  strcpy(newNode->type, type);
  strcpy(newNode->val, val);
  strcpy(newNode->code, code);

  newNode->next = NULL;
  return newNode;
}

elt_Sep_MotCle_node *createnode_Sep_MotCle(const char name[MAX_NAME_LENGTH], const char code[MAX_CODE_LENGTH])
{
  elt_Sep_MotCle_node *newNode = (elt_Sep_MotCle_node *)malloc(sizeof(elt_Sep_MotCle_node));
  if (!newNode)
  {
    return NULL;
  }
  strcpy(newNode->name, name);
  strcpy(newNode->code, code);

  newNode->next = NULL;
  return newNode;
}

void initList_Cst_Idf()
{
  list_Cst_Idf *list = (list_Cst_Idf *)malloc(sizeof(list_Cst_Idf));
  if (!list)
  {
    printf("error: initList_Cst_Idf");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  L_Cst_Idf = list;
}

void initList_Sep_MotCle()
{
  list_Sep_MotCle *list = (list_Sep_MotCle *)malloc(sizeof(list_Sep_MotCle));
  if (!list)
  {
    printf("error: initList_Sep_MotCle");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  L_Sep_MotCle = list;
}

void freeList_Cst_Idf()
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    elt_Cst_Idf_node *next = current->next;
    free(current);
    current = next;
  }
  free(L_Cst_Idf);
}

void freeList_Sep_MotCle()
{
  elt_Sep_MotCle_node *current = L_Sep_MotCle->head;
  while (current != NULL)
  {
    elt_Sep_MotCle_node *next = current->next;
    free(current);
    current = next;
  }
  free(L_Sep_MotCle);
}

void insert_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char code[MAX_CODE_LENGTH], char val[MAX_VAL_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;

  // Check if the name already exists
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      printf("ERROR: Node with the specified name already exists\n");
      return;
    }
    current = current->next;
  }

  // Name does not exist, proceed with insertion
  if (L_Cst_Idf->head == NULL)
  {
    L_Cst_Idf->head = createnode_Cst_Idf(name, type, code, val);
  }
  else
  {
    current = L_Cst_Idf->head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = createnode_Cst_Idf(name, type, code, val);
  }
}

void insert_Sep_MotCle(const char name[MAX_NAME_LENGTH], const char code[MAX_CODE_LENGTH])
{
  elt_Sep_MotCle_node *current = L_Sep_MotCle->head;

  // Check if the name already exists
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      printf("ERROR: Node with the specified name already exists\n");
      return;
    }
    current = current->next;
  }

  // Name does not exist, proceed with insertion
  if (L_Sep_MotCle->head == NULL)
  {
    L_Sep_MotCle->head = createnode_Sep_MotCle(name, code);
  }
  else
  {
    current = L_Sep_MotCle->head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = createnode_Sep_MotCle(name, code);
  }
}

void add_TYPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      strcpy(current->type, type); // Node with the specified name exists
      printf("\n\nTYPE DONE : %s \n\n", type);
      return;
    }
    current = current->next;
  }
  printf("ERROR : cant change the type node doesnt exist"); // Node with the specified name does not exist
}

void add_VALUE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char value[MAX_VAL_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      strcpy(current->val, value); // Node with the specified name exists
      printf("\n\nVALUE DONE : %s \n\n", value);
      return;
    }
    current = current->next;
  }
  printf("ERROR : cant change the value node doesnt exist"); // Node with the specified name does not exist
}

bool nodeExists_Cst_Idf(const char name[MAX_NAME_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      return true; // Node with the specified name exists
    }
    current = current->next;
  }
  return false; // Node with the specified name does not exist
}

bool nodeExists_Sep_MotCle(const char name[MAX_NAME_LENGTH])
{
  elt_Sep_MotCle_node *current = L_Sep_MotCle->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      return true; // Node with the specified name exists
    }
    current = current->next;
  }
  return false; // Node with the specified code does not exist
}

void displayList_Cst_Idf()
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;

  printf("/***************Liste des symboles IDF*************/\n");
  printf("____________________________________________________________________\n");
  printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite\n");
  printf("____________________________________________________________________\n");

  while (current != NULL)
  {
    printf("\t|%10s |%15s | %12s | %12s\n", current->name, current->code, current->type, current->val);
    current = current->next;
  }
}

void displayList_Sep_MotCle()
{
  elt_Sep_MotCle_node *current = L_Sep_MotCle->head;

  printf("/***************Liste des symboles mots clés*************/\n");
  printf("_____________________________________\n");
  printf("\t| NomEntite |  CodeEntite | \n");
  printf("_____________________________________\n");

  while (current != NULL)
  {
    printf("\t|%10s |%12s | \n", current->name, current->code);
    current = current->next;
  }
}

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
  int numDigits = snprintf(NULL, 0, "%f", number);

  // Allocate memory for the string representation
  char *result = (char *)malloc((numDigits + 1) * sizeof(char));

  // Convert the float to a string
  snprintf(result, numDigits + 1, "%f", number);

  return result;
}

//----------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>

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
