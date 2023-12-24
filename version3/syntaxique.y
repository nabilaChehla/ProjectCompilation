
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts_liste.h"
 extern  nb_ligne;
 extern Col;
 extern char fileName[50];
Stack *stack_type;
Stack *stack_value;
Stack *stack_name_Routine ; 
  char code [MAX_CODE_LENGTH];
  char Taille [MAX_VAL_LENGTH]; 
  int taille2 = 0 ; 
  int firstSize;
  int secondSize;
%}

%union {
  int     entier;
  char*   str;
  float reel; 
}


%token <str>PROGRAM_mc <str>END_mc <str>ROUTINE_mc <str>ENDR_mc <str>LOGICAL_mc <str>TRUE_mc <str>FALSE_mc <str>CHARACTER_mc <str>REAL_mc <str>INTEGER_mc <str>DIMENSION_mc <str>READ_mc <str>WRITE_mc <str>IF_mc <str>THEN_mc <str>ELSE_mc <str>ENDIF_mc <str>GT_mc <str>GE_mc <str>EQ_mc <str>NE_mc <str>LE_mc LT_mc OR_mc AND_mc DOWHILE_mc ENDDO_mc EQUIVALENCE_mc CALL_mc <str>idf <entier>cst_int   <reel>cst_real    <str>character aff plus moins divis multip pvg ver point par_ouvrante par_fermante points_sup
%start S 
%%
S : Fonction_i PROGRAM_mc idf DEC INSTRUCTIONS END_mc
;
Fonction_i: type_fonc ROUTINE_mc idf par_ouvrante ARG par_fermante DEC INSTRUCTIONS Affectation_fonction ENDR_mc Fonction_i 
                        {add_TYPE_Cst_Idf($3,top(stack_type));pop(stack_type);add_CODE_Cst_Idf($3,"ROUTINE");
                          if(strcmp(top(stack_name_Routine),$3)!=0) yyerrorSemantique("Error: the last line of ROUTINE should be affectation with name of ROUTINE") ;
                          pop(stack_name_Routine);}
           | 
;
Affectation_fonction: idf aff EXPRESSION pvg{push(stack_name_Routine,$1)}
                    | idf aff character  pvg{push(stack_name_Routine,$1)}
                    | idf LOGICAL_VALUE  pvg{push(stack_name_Routine,$1)}
;
type_fonc: type| CHARACTER_mc {push(stack_type, "CHARACTER")  }
;
ARG : liste_parametres | 
; 
liste_parametres: idf  ver liste_parametres 
                | idf par_ouvrante cst_int ver cst_int  par_fermante  ver liste_parametres 
                | idf par_ouvrante cst_int  par_fermante ver liste_parametres
                | idf
                | idf par_ouvrante cst_int ver cst_int  par_fermante
                | idf par_ouvrante cst_int  par_fermante
;

DEC: type SUITE_DEC pvg DEC {pop(stack_type)}
    |CHARACTER_mc DEC_CHAR pvg DEC  
    | DEC_TAB pvg DEC
    |
;
SUITE_DEC:  idf DEC_AFF ver SUITE_DEC  {add_TYPE_Cst_Idf($1,top(stack_type)); add_VALUE_Cst_Idf($1,top(stack_value));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE");}  
          | idf DEC_AFF                {add_TYPE_Cst_Idf($1,top(stack_type)); add_VALUE_Cst_Idf($1,top(stack_value));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE");} 
          | idf ver SUITE_DEC          {add_TYPE_Cst_Idf($1,top(stack_type));add_CODE_Cst_Idf($1,"VARIABLE");}
          | idf                        {add_TYPE_Cst_Idf($1,top(stack_type));add_CODE_Cst_Idf($1,"VARIABLE");}
 
;
DEC_TAB: type idf DIMENSION_mc par_ouvrante cst_int LIST_PAR_TAB par_fermante           {add_TYPE_Cst_Idf($2,top(stack_type));ConcatTaille($5,taille2,Taille,sizeof(Taille));add_VALUE_Cst_Idf($2,Taille) ;taille2= 0;add_CODE_Cst_Idf($2,code);}
        |CHARACTER_mc idf DIMENSION_mc par_ouvrante cst_int LIST_PAR_TAB par_fermante   {add_TYPE_Cst_Idf($2,"CHARACTER");ConcatTaille($5,taille2,Taille,sizeof(Taille));add_VALUE_Cst_Idf($2,Taille) ;taille2= 0;add_CODE_Cst_Idf($2,code);}
;

LIST_PAR_TAB : ver cst_int {taille2 = $2; strcpy(code,"MATRICE");} 
              |            {strcpy(code,"TABLEAU");}
              ;
DEC_AFF: aff cst_int  {push(stack_value, intToString($2)) } 
       | aff cst_real {push(stack_value, floatToString($2))  } 
       | aff  TRUE_mc {push(stack_value, $2)  }
       | aff FALSE_mc {push(stack_value, $2)  }
;
DEC_CHAR :    idf multip cst_int ver   DEC_CHAR            {add_TYPE_Cst_Idf($1, "CHARACTER");add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf multip cst_int                           {add_TYPE_Cst_Idf($1, "CHARACTER");add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf multip cst_int DEC_CHAR_AFF              {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,top(stack_value));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf multip cst_int DEC_CHAR_AFF ver DEC_CHAR {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,top(stack_value));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf                                          {add_TYPE_Cst_Idf($1, "CHARACTER");add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf ver DEC_CHAR                             {add_TYPE_Cst_Idf($1, "CHARACTER");add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf DEC_CHAR_AFF                             {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,top(stack_value));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE");}
          |   idf DEC_CHAR_AFF ver   DEC_CHAR              {add_TYPE_Cst_Idf($1, "CHARACTER"); add_VALUE_Cst_Idf($1,top(stack_value));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE");}
;

DEC_CHAR_AFF: aff character  {push(stack_value,$2)}
;
type:  INTEGER_mc  {push(stack_type, "INTEGER")}
     | REAL_mc     {push(stack_type, "REAL")}
     | LOGICAL_mc  {push(stack_type, "LOGICAL")}
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

Affectation: idf aff EXPRESSION pvg             {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"ROUTINE")==0) yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n")}
            |idf aff character pvg              {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"ROUTINE")==0)yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n")}
            |TAB_PAR aff EXPRESSION pvg         {/*if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"ROUTINE")==0)yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n")*/}
            |idf aff LOGICAL_VALUE pvg          {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"ROUTINE")==0)yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n")}
;

Entre_Sortie_INST:  WRITE_mc par_ouvrante SORTIE_MESSAGE par_fermante pvg 
                  | READ_mc par_ouvrante idf par_fermante pvg  {if(!idf_exist($3) || strcmp(return_CODE_Cst_Idf($3),"ROUTINE")==0) // idf n'existe pas dans TS ou est un nom de routine 
                                                                  yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n")}
;
SORTIE_MESSAGE :character ver SORTIE_MESSAGE| EXPRESSION ver SORTIE_MESSAGE | character | EXPRESSION
;
EQUIVALENCE_INST: EQUIVALENCE_mc SUITE_EQUI ver SUITE_EQUI pvg
;
SUITE_EQUI: par_ouvrante liste_parametres par_fermante
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
                   | idf {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"VARIABLE")!=0 ) // idf n'existe pas dans TS ou est un nom de routine 
                        yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n")}
;
TAB_PAR: idf par_ouvrante cst_int ver cst_int  par_fermante {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"MATRICE")!=0) // idf n'existe pas dans TS ou pas un nom de matrice 
                                                                  yyerrorSemantique("idf n'existe pas dans TS ou n'est pas une MATRICE\n");
                                                             extractIntegers_SIZE_TS(return_VALUE_SIZE_Cst_Idf($1),&firstSize,&secondSize);
                                                             if(firstSize<$3 || $3<0 || secondSize < $5 || $5 <0  )
                                                                  yyerrorSemantique("Size of matrice incorrect \n")}; 
        |idf par_ouvrante cst_int  par_fermante             {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"TABLEAU")!=0) // idf n'existe pas dans TS ou pas un nom de tableau 
                                                                 yyerrorSemantique("idf n'existe pas dans TS ou n'est pas un TABLEAU\n");
                                                            extractIntegers_SIZE_TS(return_VALUE_SIZE_Cst_Idf($1),&firstSize,&secondSize);
                                                            if(firstSize<$3 || $3<0 )
                                                                  yyerrorSemantique("Size of matrice incorrect \n");}

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
COND_SIMPLE :   
             EXPRESSION_BOOL  OPERATEUR_LOGIQUE_1  EXPRESSION_BOOL 
;
EXPRESSION_BOOL : EXPRESSION 
                | LOGICAL_VALUE 
                | par_ouvrante COND  OR_mc   SUITE_COND_1 par_fermante 
                | par_ouvrante  SUITE_COND_1  AND_mc  SUITE_COND_2 par_fermante 
                | par_ouvrante COND_SIMPLE par_fermante  
                | par_ouvrante LOGICAL_VALUE par_fermante
;
SUITE_OPERATEUR_LOGIQUE_1: LT_mc | GT_mc | NE_mc | LE_mc | GE_mc |EQ_mc 
;
LOGICAL_VALUE: TRUE_mc | FALSE_mc
;


IF_INST: IF_mc par_ouvrante  COND par_fermante THEN_mc INSTRUCTIONS SUITE_IF_INST ENDIF_mc
;
SUITE_IF_INST: ELSE_mc INSTRUCTIONS | 
;
BOUCLE_INST: DOWHILE_mc  par_ouvrante  COND par_fermante  INSTRUCTIONS ENDDO_mc pvg
;
OPERATEUR_LOGIQUE_1: point SUITE_OPERATEUR_LOGIQUE_1 point
;

INST_CALL: idf aff CALL_mc idf par_ouvrante ARG_CALL par_fermante pvg {if(!idf_exist($1) || strcmp(return_CODE_Cst_Idf($1),"ROUTINE")==0) // premier idf est une VARIABLE
                                                                                    yyerrorSemantique("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
                                                                              if(!idf_exist($4) || strcmp(return_CODE_Cst_Idf($4),"ROUTINE")!=0)  //2 eme idf doit etre une routine
                                                                                   yyerrorSemantique("L'identifiacteur appelee n'est pas une ROUTINE ou n'existe pas\n");    }
;
ARG_CALL : liste_parametres_CALL | 
; 
liste_parametres_CALL: EXPRESSION ver liste_parametres_CALL 
                      |EXPRESSION  
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
              stack_type = initializeStack();
              stack_value = initializeStack();
              stack_name_Routine = initializeStack();
            yyrestart(fileLex);

              //initialisation
               initList_Cst_Idf();
               initList_Sep_MotCle();
              yyparse(); 
              printf("syntaxe correcte \n");
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
      printf("\nFile %s, line %d, character %d: Syntaxic error\n",fileName ,nb_ligne, Col);
      displayList_Sep_MotCle();
      displayList_Cst_Idf();
      exit(EXIT_FAILURE); 
}
 int yyerrorSemantique ( char*  msg )  
{
      printf("%s",msg);
      printf("\nFile %s, line %d, character %d: semantic error\n",fileName ,nb_ligne, Col);
      displayList_Sep_MotCle();
      displayList_Cst_Idf();
      exit(EXIT_FAILURE); 
}

