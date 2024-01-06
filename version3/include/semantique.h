#ifndef SEMANTIQUE_H
#define SEMANTIQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "tools.h"
#include "ts_liste.h"



int semantiqueError(char *msg);
void CheckRoutineExiste(const char name[MAX_NAME_LENGTH]);
void Check_Retour_Routine(const char nomVariable_Retour[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void checkInit(char nomIdf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void initVar(char nomIdf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void checkIdfRead_Variable_elem(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void checkIdfRead_Variable_Tableau(Stack *stack_variable, Stack *stack_name_Routine);
void checkDoubleDeclaration(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void check_idf_Variable_Existe(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void check_idf_Matrice_Existe(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void check_idf_Tableau_Existe(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void check_idf_Aff_Call(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void check_Routine_Signature(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine, int nbArg);
void check_TypeRetour_compatible(char nomVar[MAX_NAME_LENGTH], char nomRoutine[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void check_Affectation_fin_Routine(Stack *stack_type, char save_type_operateur[MAX_TYPE_LENGTH], int *cmpt);
void checkSize(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine, int taille1, int taille2);
void checkType_affectation_idf(char idf[MAX_NAME_LENGTH], char save_type_operateur[MAX_TYPE_LENGTH], Stack *stack_name_Routine, int cmpt);
void checkType_affectation_TAB(char TAB_reference[MAX_STRING_SIZE], char save_type_operateur[MAX_TYPE_LENGTH], Stack *stack_name_Routine, int cmpt);
void check_Type_char(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void checkType_affectation_idf_Logical(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
bool activerDivPar0(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine);
void checkDivPar0(bool divZero);
bool checkTaille(char taille[], int cmpt, char code[]);
void Traitement_taille_TAB_MAT(char idf[MAX_NAME_LENGTH], char taille1[], char taille2[], char save_type_operateur[], Stack *stack_name_Routine, int cmpt, char code[]);
void check_Type_operateurs(Stack *stack_variable, Stack *stack_name_Routine, bool binaire);
void check_taille_character(const char name[MAX_NAME_LENGTH], const char scope[MAX_SCOPE_LENGTH]);
void traitement_Fin_Routine(Stack *stack_name_Routine, Stack *stack_value, Stack *stack_type);
void Taitement_SUITE_DEC(const char nomVariable[MAX_NAME_LENGTH], Stack *stack_name_Routine, Stack *stack_type);

#endif // SEMANTIQUE_H
