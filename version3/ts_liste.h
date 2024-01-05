#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
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

void add_Taille_Tab_Mat(const char *idf, char taille1[], char taille2[], Stack *stack_name_Routine)
{
  char Taille[MAX_VAL_LENGTH];
  ConcatTaille(taille1, taille2, Taille, sizeof(Taille));
  add_VALUE_Cst_Idf(idf, Taille, top(stack_name_Routine));
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

int semantiqueError(char *msg)
{
  printf("\n%s", msg);
  printf("\nFile %s, line %d, character %d: semantic error\n", fileName, nb_ligne, Col);
  displayList_Sep_MotCle();
  displayList_Cst_Idf();
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

void checkInit(char nomIdf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{ // si on a "" dans valeur dans TS donc non initalise sauf si c'est un character
  if (strcmp(return_VALUE_SIZE_Cst_Idf(nomIdf, top(stack_name_Routine)), "") == 0 && strcmp(return_TYPE_Cst_Idf(nomIdf, top(stack_name_Routine)), "CHARACTER") != 0)
  {
    semantiqueError("Utilisation d'une variable non initialise\n");
  }
}
void initVar(char nomIdf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (strcmp(return_VALUE_SIZE_Cst_Idf(nomIdf, top(stack_name_Routine)), "") == 0 && strcmp(return_TYPE_Cst_Idf(nomIdf, top(stack_name_Routine)), "CHARACTER") != 0)
  { // si on a "" dans valeur dans TS donc non initalise sauf si c'est un character
    add_VALUE_Cst_Idf(nomIdf, "-", top(stack_name_Routine));
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

void checkIdfRead_Variable_elem(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (!idf_exist(idf, top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "VARIABLE") != 0) // idf n'existe pas dans TS ou est un nom de routine
    semantiqueError("Lecture d'une VARIABLE non declare ou lecture d'une variable nom elementaire\n");
}

void checkIdfRead_Variable_Tableau(Stack *stack_variable, Stack *stack_name_Routine)
{
  if (!idf_exist(extractTableName(top(stack_variable)), top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf(extractTableName(top(stack_variable)), top(stack_name_Routine)), "ROUTINE") == 0) // idf n'existe pas dans TS ou est un nom de routine
    semantiqueError("Lecture d'un tableau non declare ou lecture d'une fonction\n");
}

void checkDoubleDeclaration(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (idf_exist(idf, top(stack_name_Routine)))
    semantiqueError("Double declaration");
}

void check_idf_Variable_Existe(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (!idf_exist(idf, top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "VARIABLE") != 0)
    semantiqueError("Utilisation de VARIABLE non declare ou afftectation a une fonction\n");
}
void check_idf_Matrice_Existe(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (!idf_exist(idf, top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "MATRICE") != 0) // idf n'existe pas dans TS ou pas un nom de matrice
    semantiqueError("idf n'existe pas dans TS ou n'est pas une MATRICE\n");
}
void check_idf_Tableau_Existe(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (!idf_exist(idf, top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "TABLEAU") != 0) // idf n'existe pas dans TS ou pas un nom de matrice
    semantiqueError("idf n'existe pas dans TS ou n'est pas un Tableau\n");
}

void check_idf_Aff_Call(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (!idf_exist(idf, top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "ROUTINE") == 0) // premier idf est une VARIABLE
    semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
}
void check_Routine_Signature(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine, int nbArg)
{
  if (atoi(return_VALUE_SIZE_Cst_Idf(idf, top(stack_name_Routine))) != nbArg)
    // signature incorrecte
    semantiqueError("Signature de la fonction incorrecte\n");
}

void check_TypeRetour_compatible(char nomVar[MAX_NAME_LENGTH], char nomRoutine[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (strcmp(return_TYPE_Cst_Idf(nomVar, top(stack_name_Routine)), return_TYPE_Cst_Idf(nomRoutine, top(stack_name_Routine))) == 0)
  {
    if (strcmp(return_TYPE_Cst_Idf(nomVar, top(stack_name_Routine)), "REAL") != 0)
    {
      if (strcmp(return_TYPE_Cst_Idf(nomRoutine, top(stack_name_Routine)), "INTEGER") == 0)
      {
        semantiqueError("Incompatibile types\n");
      }
    }
    else
    {
      semantiqueError("Incompatibile types\n");
    }
  }
}

void check_Affectation_fin_Routine(Stack *stack_type, char save_type_operateur[MAX_TYPE_LENGTH], int *cmpt)
{
  if (strcmp(top(stack_type), save_type_operateur) && (*cmpt) == 2)
  {
    if (!strcmp(top(stack_type), "REAL"))
    {
      if (strcmp(save_type_operateur, "INTEGER"))
      {
        printf("\naffectation d'une expresssion de type %s dans un idf de type %s \n", save_type_operateur, top(stack_type));
        semantiqueError("Incompatibile types\n");
      }
    }
    else
    {
      printf("\naffectation d'une expresssion de type %s dans un idf de type %s \n", save_type_operateur, top(stack_type));
      semantiqueError("Incompatibile types\n");
    }
    (*cmpt) = 0;
  }
}

void checkSize(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine, int taille1, int taille2)
{
  char firstSize[MAX_STRING_SIZE];
  char secondSize[MAX_STRING_SIZE];
  extractIntegers_SIZE_TS(return_VALUE_SIZE_Cst_Idf(idf, top(stack_name_Routine)), firstSize, secondSize);
  if (strcmp(firstSize, "-") != 0)
  {
    printf("%s | %s", firstSize, secondSize);
    if (strcmp(secondSize, "-") != 0)
    {
      if (atoi(firstSize) <= taille1 || taille1 < 0 || atoi(secondSize) < taille2 || taille2 < 0)
        semantiqueError("Size of TABLEAU / MATRICE incorrect \n");
    }
    else
    {
      if (atoi(firstSize) <= taille1 || taille1 < 0)
        semantiqueError("Size of TABLEAU / MATRICE incorrect \n");
    }
  }
  else
  {
    printf("%s | %s", firstSize, secondSize);
    if (strcmp(secondSize, "-") != 0)
      if (atoi(secondSize) < taille2 || taille2 < 0)
        semantiqueError("Size of TABLEAU / MATRICE incorrect \n");
  }
}

void checkType_affectation_idf(char idf[MAX_NAME_LENGTH], char save_type_operateur[MAX_TYPE_LENGTH], Stack *stack_name_Routine, int cmpt)
{ // checker qu'on a un type inserre dans TS car les parametres de fonctuion n'ont pas de type donc on ne fait pas le traitement
  if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "") != 0)
  {
    if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), save_type_operateur) && cmpt == 2)
    {
      if (!strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "REAL"))
      {
        if (strcmp(save_type_operateur, "INTEGER"))
        {
          printf("\naffectation d'une expresssion de type %s dans un idf de type %s \n", save_type_operateur, return_TYPE_Cst_Idf(idf, top(stack_name_Routine)));
          semantiqueError("Incompatibile types\n");
        }
      }
      else
      {
        printf("\naffectation d'une expresssion de type %s dans un idf de type %s \n", save_type_operateur, return_TYPE_Cst_Idf(idf, top(stack_name_Routine)));
        semantiqueError("Incompatibile types\n");
      }
    }
  }
}

void checkType_affectation_TAB(char TAB_reference[MAX_STRING_SIZE], char save_type_operateur[MAX_TYPE_LENGTH], Stack *stack_name_Routine, int cmpt)
{
  // checker qu'on a un type inserre dans TS car les parametres de fonctuion n'ont pas de type donc on ne fait pas le traitement
  if (strcmp(return_TYPE_Cst_Idf(TAB_reference, top(stack_name_Routine)), "") != 0)
  {
    if (strcmp(TAB_reference, save_type_operateur) && (cmpt == 3 || cmpt == 2))
    {
      if (!strcmp(TAB_reference, "REAL"))
      {
        if (strcmp(save_type_operateur, "INTEGER"))
        {
          printf("\naffectation d'une expresssion de type %s dans un idf de type %s \n", save_type_operateur, TAB_reference);
          semantiqueError("Incompatibile types\n");
        }
      }
      else
      {
        printf("\naffectation d'une expresssion de type %s dans un idf de type %s \n", save_type_operateur, TAB_reference);
        semantiqueError("Incompatibile types\n");
      }
    }
  }
}

void check_Type_char(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "") != 0)
  {
    if (strstr(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "CHARACTER") == NULL)
      semantiqueError("Incompatible types\n");
  }
}
void checkType_affectation_idf_Logical(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "") != 0)
  {
    if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "LOGICAL"))
      semantiqueError("Incompatible types\n");
  }
}

bool activerDivPar0(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
  if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "REAL") == 0 || strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "INTEGER") == 0)
  {
    if (atof(return_VALUE_SIZE_Cst_Idf(idf, top(stack_name_Routine))) == 0)
      return true;
    return false;
  }
  else
    return false;
}

void checkDivPar0(bool divZero)
{
  if (divZero == true)
    semantiqueError("Error: Division sur 0");
}

bool checkTaille(char taille[])
{

  if (strstr(taille, "temp") != NULL)
    return true;
  else
    return false;
}

void Traitement_taille_TAB_MAT(char idf[MAX_NAME_LENGTH], char taille1[], char taille2[], char save_type_operateur[], Stack *stack_name_Routine, bool SiIDF1)
{
  if (!checkTaille(taille1) && strcmp(save_type_operateur, "INTEGER"))
  {
    semantiqueError("the size 2 must be an integer");
  }
  if (!strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "MATRICE"))
  {

    if (checkTaille(taille1) && checkTaille(taille2))
    {
      add_Taille_Tab_Mat(idf, "-", "-", stack_name_Routine);
    }
    else
    {
      if (checkTaille(taille1) && !checkTaille(taille2))
      {

        if (!isdigit(taille2[0]))
        {
          add_Taille_Tab_Mat(idf, "-", return_VALUE_SIZE_Cst_Idf(taille2, top(stack_name_Routine)), stack_name_Routine);
        }
        else
        {
          add_Taille_Tab_Mat(idf, "-", taille2, stack_name_Routine);
        }
      }
      else
      {
        if (!checkTaille(taille1) && !checkTaille(taille2))
        {

          if (isdigit(taille1[0]))
          {
            if (isdigit(taille2[0]))
            {
              add_Taille_Tab_Mat(idf, taille1, taille2, stack_name_Routine);
            }
            else
            {
              add_Taille_Tab_Mat(idf, taille1, return_VALUE_SIZE_Cst_Idf(taille2, top(stack_name_Routine)), stack_name_Routine);
            }
          }
          else
          {
            printf("here2");
            if (isdigit(taille2[0]))
            {
              add_Taille_Tab_Mat(idf, return_VALUE_SIZE_Cst_Idf(taille1, top(stack_name_Routine)), taille2, stack_name_Routine);
            }
            if (!isdigit(taille2[0]))
            {
              add_Taille_Tab_Mat(idf, return_VALUE_SIZE_Cst_Idf(taille1, top(stack_name_Routine)), return_VALUE_SIZE_Cst_Idf(taille2, top(stack_name_Routine)), stack_name_Routine);
            }
          }
        }
        else if (!checkTaille(taille1) && checkTaille(taille2))
        {
          if (!isdigit(taille1[0]))
          {
            add_Taille_Tab_Mat(idf, return_VALUE_SIZE_Cst_Idf(taille1, top(stack_name_Routine)), "-", stack_name_Routine);
          }
          else
          {
            add_Taille_Tab_Mat(idf, taille1, "-", stack_name_Routine);
          }
        }
      }
    }
  }
  else
  {
    if (checkTaille(taille1))
    {
      add_Taille_Tab_Mat(idf, "-", "0", stack_name_Routine);
    }
    else
    {
      if (!isdigit(taille1[0]))
        add_Taille_Tab_Mat(idf, return_VALUE_SIZE_Cst_Idf(taille1, top(stack_name_Routine)), "0", stack_name_Routine);
      else
        add_Taille_Tab_Mat(idf, taille1, "0", stack_name_Routine);
    }
  }
}

void check_Type_operateurs(Stack *stack_variable, Stack *stack_name_Routine, bool binaire)
{
  // le plus le moins la devision ne se fait que si l'operateur et de type int ou real
  char op1[MAX_NAME_LENGTH];
  char op2[MAX_NAME_LENGTH];
  strcpy(op1, top(stack_variable));

  // if op1 est un tableau : dans pile TAB(5) -> on doit retirer TAB seulement
  if (strchr(op1, '(') != NULL && strchr(op1, ')') != NULL) // if is it tableau or matrice it containes ()
  {
    strcpy(op1, extractTableName(op1));
  }
  pop(stack_variable);
  strcpy(op2, top(stack_variable));
  // if op1 est un tableau : dans pile TAB(5) -> on doit retirer TAB seulement
  if (strchr(op2, '(') != NULL && strchr(op2, ')') != NULL) // if is it tableau or matrice it containes ()
  {
    strcpy(op2, extractTableName(op2));
  }

  if ((binaire && (idf_exist(op1, top(stack_name_Routine))) && (strcmp(return_TYPE_Cst_Idf(op1, top(stack_name_Routine)), "CHARACTER") == 0)) || ((idf_exist(op2, top(stack_name_Routine))) && strcmp(return_TYPE_Cst_Idf(op2, top(stack_name_Routine)), "CHARACTER") == 0))
  {
    semantiqueError("Cette operation ne se fait pas au type CHARACTER");
  }
  if (((binaire && (idf_exist(op1, top(stack_name_Routine)) && strcmp(return_TYPE_Cst_Idf(op1, top(stack_name_Routine)), "LOGICAL") == 0))) || ((idf_exist(op2, top(stack_name_Routine))) && strcmp(return_TYPE_Cst_Idf(op2, top(stack_name_Routine)), "LOGICAL") == 0))
  {
    semantiqueError("Cette operation ne se fait pas au type LOGICAL");
  }
  push(stack_variable, op1);
}

void check_taille_character(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH])
{
  if (strstr(return_TYPE_Cst_Idf(name, scope), "CHARACTER ") != NULL)
  {
    if (strlen(return_VALUE_SIZE_Cst_Idf(name, scope)) - 2 > return_taille_character(name, scope))
    {
      char str1[] = "La taille du character est de max ";
      strcat(str1, intToString(return_taille_character(name, scope)));
      semantiqueError(str1);
    }
  }
}
