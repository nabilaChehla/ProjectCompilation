#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "pile.h"
// Constants
#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50
#define MAX_CODE_LENGTH 50
#define MAX_VAL_LENGTH 50
#define INITIAL_CAPACITY 50
#define MAX_STRING_SIZE 50
#define MAX_SCOPE_LENGTH 50

int nb_ligne = 1;
int Col = 1;
int actTemp = 1;
char fileName[50];

typedef struct elt_Cst_Idf_node
{
  char name[MAX_NAME_LENGTH];
  char type[MAX_TYPE_LENGTH];
  char val[MAX_VAL_LENGTH];
  char code[MAX_CODE_LENGTH];
  char scope[MAX_SCOPE_LENGTH];
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

elt_Cst_Idf_node *createnode_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char code[MAX_CODE_LENGTH], const char val[MAX_VAL_LENGTH], const char scope[MAX_SCOPE_LENGTH])
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
  strcpy(newNode->scope, scope);
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
bool RoutineExiste(const char name[MAX_NAME_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if ((strcmp(current->name, name) == 0 && strcmp(current->code, "ROUTINE") == 0))
    {
      return true; // Node with the specified name exists
    }
    current = current->next;
  }
  return false;
}
void insert_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char code[MAX_CODE_LENGTH], char val[MAX_VAL_LENGTH], const char scope[MAX_SCOPE_LENGTH], Stack *stack_name_Routine)
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;

  // Check if the name already exists
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && (strcmp(current->code, "ROUTINE") == 0 || strcmp(top(stack_name_Routine), current->scope) == 0))
    {
      return;
    }

    current = current->next;
  }

  // Name does not exist, proceed with insertion
  if (L_Cst_Idf->head == NULL)
  {
    L_Cst_Idf->head = createnode_Cst_Idf(name, type, code, val, scope);
  }
  else
  {
    current = L_Cst_Idf->head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = createnode_Cst_Idf(name, type, code, val, scope);
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

void add_TYPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && strcmp(current->scope, scope) == 0)
    {
      strcpy(current->type, type); // Node with the specified name exists
      return;
    }
    current = current->next;
  }
  printf("ERROR : cant change the type node doesnt exist"); // Node with the specified name does not exist
}

void add_CODE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char code[MAX_CODE_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && strcmp(current->scope, scope) == 0)
    {
      strcpy(current->code, code); // Node with the specified name exists
      return;
    }
    current = current->next;
  }
  printf("ERROR : cant change the code node doesnt exist"); // Node with the specified name does not exist
}
char *return_CODE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && (strcmp(current->scope, scope) == 0 || strcmp(current->code, "ROUTINE") == 0))
    {
      return current->code;
    }
    current = current->next;
  }
  printf("ERROR : cant find the code node doesnt exist"); // Node with the specified name does not exist
}

char *return_TYPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && (strcmp(current->scope, scope) == 0 || strcmp(current->code, "ROUTINE") == 0))
    {
      return current->type;
    }
    current = current->next;
  }
  printf("ERROR : cant find the code node doesnt exist"); // Node with the specified name does not exist
}

char *return_VALUE_SIZE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && (strcmp(current->scope, scope) == 0 || strcmp(current->code, "ROUTINE") == 0))
    {
      return current->val;
    }
    current = current->next;
  }
  printf("ERROR : cant find the val node doesnt exist"); // Node with the specified name does not exist
}

void add_VALUE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char value[MAX_VAL_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && (strcmp(current->scope, scope) == 0 || strcmp(current->code, "ROUTINE") == 0))
    {
      strcpy(current->val, value); // Node with the specified name exists
      return;
    }
    current = current->next;
  }
  printf("ERROR : cant change the value node doesnt exist"); // Node with the specified name does not exist
}
void add_SCOPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && strcmp(current->scope, "") == 0)
    {
      strcpy(current->scope, scope); // Node with the specified name exists
      return;
    }
    current = current->next;
  }
}

bool idf_exist(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0 && strcmp(current->scope, scope) == 0)
    {
      if (strcmp(current->code, "") == 0)
        return false; // donc vbariable existe dans TS mais non declarer dans partie declaration de la syntaxique
      else
        return true; // Node with the specified name exists
    }
    current = current->next;
  }
  return false; // Node with the specified name does not exist
}

void CheckRoutineExiste(const char name[MAX_NAME_LENGTH])
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  while (current != NULL)
  {
    if ((strcmp(current->name, name) == 0 && strcmp(current->code, "ROUTINE") == 0))
    {
      return; // Node with the specified name exists
    }
    current = current->next;
  }
  semantiqueError("La routine appelee n'existe pas"); // Node with the specified name does not exist
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
  printf("__________________________________________________________________________________\n");
  printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite/taille/nbArg | scope\n");
  printf("__________________________________________________________________________________\n");

  while (current != NULL)
  {
    printf("\t|%10s |%15s | %12s | %20s | %1s\n", current->name, current->code, current->type, current->val, current->scope);
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

void add_Taille_Tab_Mat(const char *idf, int taille1, int taille2, Stack *stack_name_Routine)
{
  char Taille[MAX_VAL_LENGTH];
  ConcatTaille(taille1, taille2, Taille, sizeof(Taille));
  add_VALUE_Cst_Idf(idf, Taille, top(stack_name_Routine));
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
int semantiqueError(char *msg)
{
  printf("%s", msg);
  printf("\nFile %s, line %d, character %d: semantic error\n", fileName, nb_ligne, Col);
  displayList_Sep_MotCle();
  exit(EXIT_FAILURE);
}

void traitement_Fin_Routine(Stack *stack_name_Routine, Stack *stack_value, Stack *stack_type)
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
