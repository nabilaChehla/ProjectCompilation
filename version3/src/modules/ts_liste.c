#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "../include/ts_liste.h"
#include "../include/tools.h"

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
    printf("\nERROR: initList_Cst_Idf");
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
    printf("ERROR: initList_Sep_MotCle");
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
  printf("ERROR : cant find the type node doesnt exist"); // Node with the specified name does not exist
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

int return_taille_character(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  char *type_idf = return_TYPE_Cst_Idf(name, scope);
  int result = 0;

  // Declare loop variable outside the loop
  int i = 0;

  // Iterate through each character in the string
  while (type_idf[i] != '\0')
  {
    // Skip non-digit characters
    while (type_idf[i] != '\0' && (type_idf[i] < '0' || type_idf[i] > '9'))
    {
      ++i;
    }

    // Break the loop if a non-digit character is encountered
    if (type_idf[i] == '\0')
    {
      break;
    }

    // Update the result by multiplying it by 10 and adding the new digit
    result = result * 10 + (type_idf[i] - '0');

    // Move to the next character
    ++i;
  }

  return result;
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

void add_Taille_Tab_Mat(const char *idf, char taille1[], char taille2[], Stack *stack_name_Routine)
{
  char Taille[MAX_VAL_LENGTH];
  ConcatTaille(taille1, taille2, Taille, sizeof(Taille));
  add_VALUE_Cst_Idf(idf, Taille, top(stack_name_Routine));
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
void removeEmptyStrings(list_Cst_Idf *myList)
{
  elt_Cst_Idf_node *current = myList->head;
  elt_Cst_Idf_node *prev = NULL;

  while (current != NULL)
  {
    if (
        strcmp(current->type, "") == 0 &&
        strcmp(current->val, "") == 0 &&
        strcmp(current->code, "") == 0 &&
        strcmp(current->scope, "") == 0)
    {
      if (prev == NULL)
      {
        myList->head = current->next;
      }
      else
      {
        prev->next = current->next;
      }

      free(current);
      current = (prev == NULL) ? myList->head : prev->next;
    }
    else
    {
      prev = current;
      current = current->next;
    }
  }
}
void displayList_Cst_Idf()
{
  elt_Cst_Idf_node *current = L_Cst_Idf->head;
  removeEmptyStrings(L_Cst_Idf);
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
