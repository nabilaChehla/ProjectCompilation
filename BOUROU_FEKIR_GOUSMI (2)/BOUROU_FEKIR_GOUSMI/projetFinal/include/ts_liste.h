#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

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

elt_Cst_Idf_node *createnode_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char code[MAX_CODE_LENGTH], const char val[MAX_VAL_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
elt_Sep_MotCle_node *createnode_Sep_MotCle(const char name[MAX_NAME_LENGTH], const char code[MAX_CODE_LENGTH]);
void initList_Cst_Idf();
void initList_Sep_MotCle();
void freeList_Cst_Idf();
void freeList_Sep_MotCle();
bool RoutineExiste(const char name[MAX_NAME_LENGTH]);
void insert_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char code[MAX_CODE_LENGTH], char val[MAX_VAL_LENGTH], const char scope[MAX_SCOPE_LENGTH], Stack *stack_name_Routine);
void insert_Sep_MotCle(const char name[MAX_NAME_LENGTH], const char code[MAX_CODE_LENGTH]);
void add_TYPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char type[MAX_TYPE_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
void add_CODE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char code[MAX_CODE_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
char *return_CODE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
char *return_TYPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
char *return_VALUE_SIZE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
void add_VALUE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char value[MAX_VAL_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
int return_taille_character(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
void add_SCOPE_Cst_Idf(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
void add_Taille_Tab_Mat(const char *idf, char taille1[], char taille2[], Stack *stack_name_Routine);
bool idf_exist(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
bool nodeExists_Sep_MotCle(const char name[MAX_NAME_LENGTH]);
void removeEmptyStrings(list_Cst_Idf *myList);
void displayList_Cst_Idf();
void displayList_Sep_MotCle();
#endif // TS_H
