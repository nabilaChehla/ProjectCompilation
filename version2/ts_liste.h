#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct elt_Cst_Idf_node
{
  char name[20];
  char type[20];
  float val;
  char code[20];
  struct elt_Cst_Idf_node *next;
} elt_Cst_Idf_node;

typedef struct elt_Sep_MotCle_node
{
  char name[20];
  char code[20];
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

/*----------------------------------------------------*/

elt_Cst_Idf_node *createnode_Cst_Idf(const char name[20], const char type[20], const char code[20], float val)
{
  elt_Cst_Idf_node *newNode = (elt_Cst_Idf_node *)malloc(sizeof(elt_Cst_Idf_node));
  if (!newNode)
  {
    return NULL;
  }
  strcpy(newNode->name, name);
  strcpy(newNode->type, type);
  newNode->val = val;
  strcpy(newNode->code, code);

  newNode->next = NULL;
  return newNode;
}

elt_Sep_MotCle_node *createnode_Sep_MotCle(const char name[20], const char code[20])
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
void insert_Cst_Idf(const char name[20], const char type[20], const char code[20], float val)
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

void insert_Sep_MotCle(const char name[20], const char code[20])
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

void add_TYPE_Cst_Idf(const char name[20], char type[20])
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

bool nodeExists_Cst_Idf(const char name[20])
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

bool nodeExists_Sep_MotCle(const char name[20])
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
    printf("\t|%10s |%15s | %12s | %12f\n", current->name, current->code, current->type, current->val);
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
