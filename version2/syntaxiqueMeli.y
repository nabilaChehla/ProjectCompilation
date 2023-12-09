
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts_liste.h"
  int nb_ligne=1, Col=1;
  char fileName[50];
  char save_type[MAX_TYPE_LENGTH]; 
  char save_val[MAX_VAL_LENGTH]; 

%}

%union {
  int     entier;
  char*   str;
  float reel; 
}


%token <str>PROGRAM_mc <str>END_mc <str>ROUTINE_mc <str>ENDR_mc <str>LOGICAL_mc <str>TRUE_mc <str>FALSE_mc <str>CHARACTER_mc <str>REAL_mc <str>INTEGER_mc <str>DIMENSION_mc <str>READ_mc <str>WRITE_mc <str>IF_mc <str>THEN_mc <str>ELSE_mc <str>ENDIF_mc <str>GT_mc <str>GE_mc <str>EQ_mc <str>NE_mc <str>LE_mc LT_mc OR_mc AND_mc DOWHILE_mc ENDDO_mc EQUIVALENCE_mc CALL_mc <str>idf <entier>cst_int  <reel>cst_real   <str>character aff plus moins divis multip pvg ver point par_ouvrante par_fermante points_sup
%start S 
%%
S : Fonction_i PROGRAM_mc idf DEC INSTRUCTIONS END_mc{printf("syntaxe correcte \n"); YYACCEPT;}
;
Fonction_i: type_fonc ROUTINE_mc idf par_ouvrante liste_parametres par_fermante DEC INSTRUCTIONS Affectation ENDR_mc Fonction_i {add_TYPE_Cst_Idf($3, save_type);}
           | 
;
type_fonc: type| CHARACTER_mc {strcpy(save_type,$1);  }
;
liste_parametres: EXPRESSION  SUITE_liste_parametres | TAB_PAR liste_parametres
;
SUITE_liste_parametres: ver liste_parametres 
                        |

;
TAB_PAR: idf par_ouvrante EXPRESSION LIST_PAR_TAB par_fermante 
;
LIST_PAR_TAB : ver EXPRESSION |
;
EXPRESSION:  EXPRESSION plus SUITE_EXPRESSION_1
           | EXPRESSION moins SUITE_EXPRESSION_1
           | SUITE_EXPRESSION_1
;

SUITE_EXPRESSION_1:  SUITE_EXPRESSION_1 multip SUITE_EXPRESSION_2
                   | SUITE_EXPRESSION_1 divis SUITE_EXPRESSION_2
                   | SUITE_EXPRESSION_2
;

SUITE_EXPRESSION_2:  par_ouvrante EXPRESSION par_fermante
                   | cst_int
                   | cst_real
                   | TAB_PAR
                   | idf
;
DEC: type SUITE_DEC pvg DEC 
    |CHARACTER_mc DEC_CHAR pvg DEC | 
;
SUITE_DEC:  idf DEC_AFF ver SUITE_DEC {add_TYPE_Cst_Idf($1,save_type); add_VALUE_Cst_Idf($1,save_val)};  
          | idf DEC_AFF {add_TYPE_Cst_Idf($1,save_type); add_VALUE_Cst_Idf($1,save_val)} 
          | idf ver SUITE_DEC {add_TYPE_Cst_Idf($1,save_type)}; 
          | idf  {add_TYPE_Cst_Idf($1,save_type)}; 
          | idf DIMENSION_mc par_ouvrante EXPRESSION LIST_PAR_TAB par_fermante  ver SUITE_DEC {add_TYPE_Cst_Idf($1, save_type)}
          | idf DIMENSION_mc par_ouvrante EXPRESSION LIST_PAR_TAB par_fermante {add_TYPE_Cst_Idf($1, save_type)}
;
DEC_AFF: aff cst_int {strcpy(save_val,intToString($2));} | aff cst_real {strcpy(save_val,floatToString($2));} | aff  TRUE_mc {strcpy(save_val,$2);}| aff FALSE_mc{strcpy(save_val,$2);}
;
DEC_CHAR :  idf multip cst_int ver   DEC_CHAR {add_TYPE_Cst_Idf($1, "CHARACTER")}
          |  idf multip cst_int  {add_TYPE_Cst_Idf($1, "CHARACTER");}
          |   idf multip cst_int DEC_CHAR_AFF  {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,save_val)}
          |   idf multip cst_int DEC_CHAR_AFF ver DEC_CHAR {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,save_val)}
          |   idf  {add_TYPE_Cst_Idf($1, "CHARACTER");}
          |   idf ver DEC_CHAR {add_TYPE_Cst_Idf($1, "CHARACTER")}
          |   idf DEC_CHAR_AFF {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,save_val)}
          |   idf DEC_CHAR_AFF ver   DEC_CHAR   {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,save_val)}
;

DEC_CHAR_AFF: aff character  {strcpy(save_val,$2)}
;
type:  INTEGER_mc  {strcpy(save_type,$1);  }
     | REAL_mc     {strcpy(save_type,$1);  }
     | LOGICAL_mc  {strcpy(save_type,$1);  }
;

INSTRUCTIONS: INSTRUCTIONS TYPE_INSTRUCTION
              |
;
TYPE_INSTRUCTION : Affectation
                  |Entre_Sortie_INST
                  |EQUIVALENCE_INST
                  |BOUCLE_INST
                  |IF_INST
                  |INST_CALL
;

Affectation: idf aff EXPRESSION pvg 
            |idf aff character pvg 
            |idf par_ouvrante EXPRESSION LIST_PAR_TAB par_fermante aff EXPRESSION pvg 
            |idf aff TRUE_mc pvg 
            |idf aff FALSE_mc pvg 
;

Entre_Sortie_INST:  WRITE_mc par_ouvrante SORTIE_MESSAGE par_fermante pvg 
                  | READ_mc par_ouvrante idf par_fermante pvg
;
SORTIE_MESSAGE :character ver SORTIE_MESSAGE| EXPRESSION ver SORTIE_MESSAGE | character | EXPRESSION
;
EQUIVALENCE_INST: EQUIVALENCE_mc SUITE_EQUI ver SUITE_EQUI pvg
;
SUITE_EQUI: par_ouvrante liste_parametres par_fermante
;


COND:   COND  OR_mc   SUITE_COND_1
      | SUITE_COND_1
;
SUITE_COND_1:  SUITE_COND_1  AND_mc  SUITE_COND_2
             | SUITE_COND_2
;
SUITE_COND_2:   EXPRESSION_BOOL
              | COND_SIMPLE
;
COND_SIMPLE :  COND_SIMPLE   OPERATEUR_LOGIQUE_1  EXPRESSION_BOOL 
             | EXPRESSION_BOOL  OPERATEUR_LOGIQUE_1  EXPRESSION_BOOL 
;
EXPRESSION_BOOL : EXPRESSION | LOGICAL_VALUE | par_ouvrante COND par_fermante
;
SUITE_OPERATEUR_LOGIQUE_1: LT_mc | GT_mc | NE_mc | LE_mc | GE_mc |EQ_mc 
;
LOGICAL_VALUE: TRUE_mc | FALSE_mc
;


IF_INST: IF_mc par_ouvrante  COND par_fermante THEN_mc INSTRUCTIONS SUITE_IF_INST ENDIF_mc
;
SUITE_IF_INST: ELSE_mc INSTRUCTIONS | 
;
BOUCLE_INST: DOWHILE_mc  par_ouvrante  COND par_fermante  INSTRUCTIONS ENDDO_mc
;
OPERATEUR_LOGIQUE_1: point SUITE_OPERATEUR_LOGIQUE_1 point
;

INST_CALL: idf aff CALL_mc idf par_ouvrante liste_parametres par_fermante pvg
;
%%


int main(int argc , char *argv[]) {
    if(argc==2){
        FILE* fileLex =  fopen( argv[1], "r"); 
        strcpy(fileName,argv[1]);
        if(fileLex == NULL ){
            printf("ERROR:probably file doesn't exist ");
            return EXIT_FAILURE ; 
        }
        else{
            yyrestart(fileLex);

              //initialisation
               initList_Cst_Idf();
               initList_Sep_MotCle();
              printf("test 00\n");
              yyparse(); 
              displayList_Sep_MotCle();
              displayList_Cst_Idf();
            fclose(fileLex); 
             return EXIT_SUCCESS;
        }


    }
    else{
        printf("too much or too littel aruments \n"); 
                return EXIT_FAILURE ; 
    }

}
yywrap ()
{}
int yyerror ( char*  msg )  
{
      printf("File %s, line %d, character %d: Syntaxic error\n",fileName ,nb_ligne, Col);
}
 

