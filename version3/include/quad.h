#ifndef QDR_H
#define QDR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "tools.h"

// Constants
#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50
#define MAX_CODE_LENGTH 50
#define MAX_VAL_LENGTH 50
#define INITIAL_CAPACITY 50
#define MAX_STRING_SIZE 50
#define MAX_SCOPE_LENGTH 50

typedef struct qdr
{

  char oper[100];
  char op1[100];
  char op2[100];
  char res[100];

} qdr;
qdr quad[1000];
extern int qc;
extern int actTemp;

void quadr(char opr[], char op1[], char op2[], char res[]);
void ajour_quad(int num_quad, int colon_quad, char val[]);
void afficher_qdr();
void quadExpression(Stack *stack_variable, char opr[MAX_STRING_SIZE]);
void quadOpUnaire(Stack *stack_variable, char opr[MAX_STRING_SIZE]);
void Tab_idfInStack_Quad(Stack *stack_variable, const char idf[MAX_NAME_LENGTH], int taille1, int taille2);
void quadParametre(Stack *stack_variable, int nbParametres);
void quadArgument(Stack *stack_variable);
void quadRead(char idf_Argument[MAX_NAME_LENGTH]);

#endif // QDR_H
