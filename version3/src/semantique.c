#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "../include/semantique.h"
#include "modules/tools.c"
#include "modules/ts_liste.c"

int semantiqueError(char *msg)
{
    printf("\n%s", msg);
    printf("\nFile %s, line %d, character %d: semantic error\n", fileName, nb_ligne, Col);
    displayList_Sep_MotCle();
    displayList_Cst_Idf();
    exit(EXIT_FAILURE);
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

void Check_Retour_Routine(const char nomVariable_Retour[MAX_NAME_LENGTH], Stack *stack_name_Routine)
{
    if (strcmp(nomVariable_Retour, top(stack_name_Routine)) != 0)
        semantiqueError("Le nom de cette variable doit etre le meme que cele de la routine");
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
    if (strcmp(return_TYPE_Cst_Idf(nomVar, top(stack_name_Routine)), return_TYPE_Cst_Idf(nomRoutine, top(stack_name_Routine))) != 0)
    {
        if (strcmp(return_TYPE_Cst_Idf(nomVar, top(stack_name_Routine)), "REAL") == 0)
        {
            if (strcmp(return_TYPE_Cst_Idf(nomRoutine, top(stack_name_Routine)), "INTEGER") != 0)
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

void checkSize(char idf[MAX_NAME_LENGTH], Stack *stack_name_Routine, char taille1[], char taille2[])
{
    char firstSize[MAX_STRING_SIZE];
    char secondSize[MAX_STRING_SIZE];
    extractIntegers_SIZE_TS(return_VALUE_SIZE_Cst_Idf(idf, top(stack_name_Routine)), firstSize, secondSize);
    if (strcmp(firstSize, "-") != 0)
    {
        if (strcmp(secondSize, "-") != 0 && strcmp(secondSize, "0") != 0)
        {
            if (atoi(firstSize) <= atoi(taille1) || atoi(taille1) < 0 || (atoi(secondSize) <= atoi(taille2) || atoi(taille2) < 0))
                semantiqueError("Size of TABLEAU / MATRICE incorrect \n");
        }
        else
        {
            if (atoi(firstSize) <= atoi(taille1) || atoi(taille1) < 0)
                semantiqueError("Size of TABLEAU / MATRICE incorrect \n");
        }
    }
    else
    {
        if (strcmp(secondSize, "-") != 0 && strcmp(secondSize, "0") != 0)
            if (atoi(secondSize) <= atoi(taille2) || atoi(taille2) < 0)
                semantiqueError("Size of TABLEAU / MATRICE incorrect \n");
    }
}

void checkType_affectation_idf(char idf[MAX_NAME_LENGTH], char save_type_operateur[MAX_TYPE_LENGTH], Stack *stack_name_Routine, int cmpt)
{ // checker qu'on a un type inserre dans TS car les parametres de fonctuion n'ont pas de type donc on ne fait pas le traitement
    if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "") != 0)
    {
        printf("typeeeeeee %d", cmpt);

        if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), save_type_operateur) != 0 && (cmpt == 2 || cmpt == 1))
        {

            if (strcmp(return_TYPE_Cst_Idf(idf, top(stack_name_Routine)), "REAL") == 0)
            {

                if (strcmp(save_type_operateur, "INTEGER") != 0)
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

bool checkTaille(char taille[], int cmpt, char code[])
{
    if (strcmp(code, "MATRICE") == 0)
    {
        if (strstr(taille, "temp") != NULL && cmpt > 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (strstr(taille, "temp") != NULL && cmpt > 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool checkBounds(char taille[])
{

    if (strstr(taille, "temp") != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Traitement_taille_DEC_TAB_MAT(char *idf, char taille1[], char taille2[], Stack *stack_name_Routine)
{
    printf("Debug: taille1='%s', taille2='%s'\n", taille1, taille2);
    int taille1_int = atoi(taille1);
    int taille2_int = atoi(taille2);

    printf("Debug: taille1_int=%d, taille2_int=%d\n", taille1_int, taille2_int);

    if (taille1_int < 1)
    {
        semantiqueError("La taille du Tableau/Matrice doit être strictement positive");
    }
    else
    {
        if (taille2_int < 1 && strcmp(return_CODE_Cst_Idf(idf, top(stack_name_Routine)), "MATRICE") == 0)
            semantiqueError("La taille du Tableau/Matrice doit être strictement positive");
        else
            add_Taille_Tab_Mat(idf, taille1, taille2, stack_name_Routine);
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
    if (strstr(return_TYPE_Cst_Idf(name, scope), "CHARACTER") != NULL)
    {
        if (strlen(return_VALUE_SIZE_Cst_Idf(name, scope)) - 2 > return_taille_character(name, scope))
        {
            char str1[] = "La taille du character est de max ";
            strcat(str1, intToString(return_taille_character(name, scope)));
            semantiqueError(str1);
        }
    }
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

void Taitement_SUITE_DEC(const char nomVariable[MAX_NAME_LENGTH], Stack *stack_name_Routine, Stack *stack_type)
{
    if (idf_exist(nomVariable, top(stack_name_Routine)))
        semantiqueError("Double declaration");
    add_SCOPE_Cst_Idf(nomVariable, top(stack_name_Routine));
    add_TYPE_Cst_Idf(nomVariable, top(stack_type), top(stack_name_Routine));

    add_CODE_Cst_Idf(nomVariable, "VARIABLE", top(stack_name_Routine));
}
