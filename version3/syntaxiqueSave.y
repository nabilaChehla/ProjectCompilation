
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
  char save_type_operateur [MAX_TYPE_LENGTH];
  char TAB_reference[50];
  char Type_routine[50];
  int taille2 = 0 ; 
  int firstSize;
  int secondSize;
  int nbArg = 0 ; 
  int cmpt= 0;
  bool divZero = false ;
%}

%union {
  int     entier;
  char*   str;
  float reel; 
}


%token <str>PROGRAM_mc <str>END_mc <str>ROUTINE_mc <str>ENDR_mc <str>LOGICAL_mc <str>TRUE_mc <str>FALSE_mc <str>CHARACTER_mc <str>REAL_mc <str>INTEGER_mc <str>DIMENSION_mc <str>READ_mc <str>WRITE_mc <str>IF_mc <str>THEN_mc <str>ELSE_mc <str>ENDIF_mc <str>GT_mc <str>GE_mc <str>EQ_mc <str>NE_mc <str>LE_mc LT_mc OR_mc AND_mc DOWHILE_mc ENDDO_mc EQUIVALENCE_mc CALL_mc <str>idf <entier>cst_int   <reel>cst_real    <str>character aff plus moins divis multip pvg ver point par_ouvrante par_fermante points_sup
%start S 
%%
S : Fonction_i  MAIN DEC INSTRUCTIONS END_mc
;
MAIN: PROGRAM_mc  idf {push(stack_name_Routine,"main")}
;
Fonction_i: fonc  Fonction_i 
                        { traitement_Fin_Routine(stack_name_Routine,stack_value,stack_type);  nbArg = 0;
                        
                        }
           | 
;
fonc: save_name_func par_ouvrante ARG par_fermante DEC INSTRUCTIONS Affectation_fonction ENDR_mc
                 {      if( strcmp(top(stack_type),save_type_operateur) && cmpt==2){ 
                              if(!strcmp(top(stack_type),"REAL")){
                                   if(strcmp(save_type_operateur,"INTEGER")){
                                          printf("affectation d'une expresssion de type %s dans un idf de type %s \n",save_type_operateur,top(stack_type)); 
                                          semantiqueError("Incompatibile types\n");}
                                    }else{
                                          printf("affectation d'une expresssion de type %s dans un idf de type %s \n",save_type_operateur,top(stack_type)); 
                                          semantiqueError("Incompatibile types\n");
                                    }
                                    cmpt=0;
                          }
                  }

;
save_name_func: type_fonc ROUTINE_mc idf {push(stack_name_Routine,$3);}
;
Affectation_fonction: idf aff EXP pvg      {Check_Retour_Routine($1, stack_name_Routine);
                                                
                                          }
                    | idf aff character pvg {Check_Retour_Routine($1, stack_name_Routine);
                                             strcpy(save_type_operateur,"CHARACTER");
                                             cmpt=cmpt+2;
                                            }
                    | idf LOGICAL_VALUE pvg {Check_Retour_Routine($1, stack_name_Routine);
                                             strcpy(save_type_operateur,"LOGICAL");
                                              cmpt=cmpt+2;
                                            }
;
type_fonc: type | CHARACTER_mc {push(stack_type, "CHARACTER")  }
;
ARG : liste_parametres {push(stack_value,intToString(nbArg)); nbArg=0;}
      |                {push(stack_value,"0"); nbArg=0;}
; 
liste_parametres: idf  ver liste_parametres                                                {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));nbArg++}                                      
                | idf par_ouvrante cst_int ver cst_int  par_fermante  ver liste_parametres {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));nbArg++}
                | idf par_ouvrante cst_int  par_fermante ver liste_parametres              {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));nbArg++}
                | idf                                                                      {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));nbArg++}
                | idf par_ouvrante cst_int ver cst_int  par_fermante                       {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));nbArg++}
                | idf par_ouvrante cst_int  par_fermante                                   {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));nbArg++}
;

DEC: type SUITE_DEC pvg DEC {pop(stack_type)}
    |CHARACTER_mc DEC_CHAR pvg DEC  
    | DEC_TAB pvg DEC
    |
;
SUITE_DEC:  idf DEC_AFF ver SUITE_DEC  {Taitement_SUITE_DEC($1,stack_name_Routine,stack_type); add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine)); pop(stack_value);}  
          | idf DEC_AFF                {Taitement_SUITE_DEC($1,stack_name_Routine,stack_type); add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine)); pop(stack_value);}  
          | idf ver SUITE_DEC          {Taitement_SUITE_DEC($1,stack_name_Routine,stack_type)} 
          | idf                        {Taitement_SUITE_DEC($1,stack_name_Routine,stack_type)} 
 
;
DEC_TAB: type idf DIMENSION_mc par_ouvrante cst_int LIST_PAR_TAB par_fermante           {if(idf_exist($2,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($2,top(stack_name_Routine));add_TYPE_Cst_Idf($2,top(stack_type),top(stack_name_Routine));ConcatTaille($5,taille2,Taille,sizeof(Taille));add_VALUE_Cst_Idf($2,Taille,top(stack_name_Routine)) ;taille2= 0;add_CODE_Cst_Idf($2,code,top(stack_name_Routine));pop(stack_type)}
        |CHARACTER_mc idf DIMENSION_mc par_ouvrante cst_int LIST_PAR_TAB par_fermante   {if(idf_exist($2,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($2,top(stack_name_Routine));add_TYPE_Cst_Idf($2,"CHARACTER",top(stack_name_Routine));ConcatTaille($5,taille2,Taille,sizeof(Taille));add_VALUE_Cst_Idf($2,Taille,top(stack_name_Routine)) ;taille2= 0;add_CODE_Cst_Idf($2,code,top(stack_name_Routine));}
;

LIST_PAR_TAB : ver cst_int {taille2 = $2; strcpy(code,"MATRICE");} 
              |            {strcpy(code,"TABLEAU");}
              ;
DEC_AFF: aff cst_int  {push(stack_value, intToString($2)) } 
       | aff cst_real {push(stack_value, floatToString($2))  } 
       | aff  TRUE_mc {push(stack_value, $2)  }
       | aff FALSE_mc {push(stack_value, $2)  }
;
DEC_CHAR :    idf multip cst_int ver   DEC_CHAR            {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf multip cst_int                           {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf multip cst_int DEC_CHAR_AFF              {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf multip cst_int DEC_CHAR_AFF ver DEC_CHAR {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf                                          {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf ver DEC_CHAR                             {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf DEC_CHAR_AFF                             {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf DEC_CHAR_AFF ver   DEC_CHAR              {if(idf_exist($1,top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
;

DEC_CHAR_AFF: aff character  {push(stack_value,$2)}
;
type:  INTEGER_mc  {push(stack_type, "INTEGER");printf("Here type rout :%s\n",top(stack_type))}
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

Affectation: idf aff EXP pvg             {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"ROUTINE")==0) semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
                                          if( strcmp(return_TYPE_Cst_Idf($1,top(stack_name_Routine)),save_type_operateur) && cmpt==2 ){ 
                                                if(!strcmp(return_TYPE_Cst_Idf($1,top(stack_name_Routine)),"REAL")){
                                                      if(strcmp(save_type_operateur,"INTEGER")){
                                                            printf("affectation d'une expresssion de type %s dans un idf de type %s \n",save_type_operateur,top(stack_type)); 
                                                            semantiqueError("Incompatibile types\n");}
                                                      }else{
                                                            printf("affectation d'une expresssion de type %s dans un idf de type %s \n",save_type_operateur,top(stack_type)); 
                                                            semantiqueError("Incompatibile types\n");
                                                      }
                                          }
                                                cmpt=0;
                                          }
            |idf aff character pvg        {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"ROUTINE")==0)semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
                                           if(strcmp(return_TYPE_Cst_Idf($1,top(stack_name_Routine)),"CHARACTER")) semantiqueError("Incompatible types\n")}
            |TAB_PAR aff EXP pvg          {/*if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1),"ROUTINE",top(stack_name_Routine))==0)semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n")*/
                                           if( strcmp(TAB_reference,save_type_operateur) && (cmpt==3 || cmpt==2)){
                                                if(!strcmp(TAB_reference,"REAL")){
                                                      if(strcmp(save_type_operateur,"INTEGER")){
                                                            printf("affectation d'une expresssion de type %s dans un idf de type %s \n",save_type_operateur,TAB_reference); 
                                                            semantiqueError("Incompatibile types\n");}
                                                }else{
                                                      printf("affectation d'une expresssion de type %s dans un idf de type %s \n",save_type_operateur,TAB_reference); 
                                                            semantiqueError("Incompatibile types\n");
                                                }
                                                
                                           }
                                                cmpt=0; 
                                          }                                   
            
            |idf aff LOGICAL_VALUE pvg    {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"ROUTINE")==0)semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
                                           if(strcmp(return_TYPE_Cst_Idf($1,top(stack_name_Routine)),"LOGICAL")) semantiqueError("Incompatible types\n");}

;

Entre_Sortie_INST:  WRITE_mc par_ouvrante SORTIE_MESSAGE par_fermante pvg 
                  | READ_mc par_ouvrante idf par_fermante pvg  {if(!idf_exist($3,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($3,top(stack_name_Routine)),"ROUTINE")==0) // idf n'existe pas dans TS ou est un nom de routine 
                                                                  semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n")}
;
SORTIE_MESSAGE :character ver SORTIE_MESSAGE
               | EXP ver SORTIE_MESSAGE       { cmpt=0; }
               | character 
               | EXP                          { cmpt=0; }
;
EQUIVALENCE_INST: EQUIVALENCE_mc SUITE_EQUI ver SUITE_EQUI pvg
;
SUITE_EQUI: par_ouvrante liste_parametres_Eq par_fermante 
;
EXP :EXPRESSION {divZero=false }
;
EXPRESSION:  EXPRESSION plus SUITE_EXPRESSION_1 {divZero=false }
           | EXPRESSION moins SUITE_EXPRESSION_1{divZero=false }
           | SUITE_EXPRESSION_1                 {}
;

SUITE_EXPRESSION_1:  SUITE_EXPRESSION_1 multip SUITE_EXPRESSION_2{divZero=false}
                   | SUITE_EXPRESSION_1 divis suiteDiv           {divZero=false;}
                   | SUITE_EXPRESSION_2                          {}              
;
suiteDiv: SUITE_EXPRESSION_2 {if(divZero==true)semantiqueError("Error: Division sur 0");}
;
SUITE_EXPRESSION_2:  par_ouvrante EXPRESSION par_fermante {}
                   | cst_int  {if($1==0)divZero=true;else divZero = false ;    
                              if (cmpt==0 || cmpt==1) strcpy(save_type_operateur,"INTEGER"); 
                              cmpt=cmpt+2;

                              }      
                   | cst_real {if($1==0)divZero=true;else divZero = false;
                              if (cmpt==0 || cmpt==1) strcpy(save_type_operateur,"REAL");            
                              cmpt=cmpt+2;
                              }
                   | TAB_PAR  {  divZero = false  } 
                   | idf {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"VARIABLE")!=0 ) // idf n'existe pas dans TS ou est un nom de routine 
                                    semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
                              if(atof(return_VALUE_SIZE_Cst_Idf($1,top(stack_name_Routine)))==0)divZero=true;else divZero = false ;  
                              if (cmpt==0 || cmpt==1) strcpy(save_type_operateur,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 
                              cmpt=cmpt+2;

                            }
;
TAB_PAR: idf par_ouvrante cst_int ver cst_int  par_fermante {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"MATRICE")!=0) // idf n'existe pas dans TS ou pas un nom de matrice 
                                                                  semantiqueError("idf n'existe pas dans TS ou n'est pas une MATRICE\n");
                                                             extractIntegers_SIZE_TS(return_VALUE_SIZE_Cst_Idf($1,top(stack_name_Routine)),&firstSize,&secondSize);
                                                             if(firstSize<=$3 || $3<0 || secondSize < $5 || $5 <0  )
                                                                  semantiqueError("Size of matrice incorrect \n");
                                                            if (cmpt ==0)
                                                              strcpy(TAB_reference,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 

                                                            if (cmpt==1 ) { 
                                                                  
                                                                  strcpy(save_type_operateur,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 
                                                                  
                                                             }
                                                             cmpt++;
                                                            }
        |idf par_ouvrante cst_int  par_fermante             {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"TABLEAU")!=0) // idf n'existe pas dans TS ou pas un nom de tableau 
                                                                 semantiqueError("idf n'existe pas dans TS ou n'est pas un TABLEAU\n");
                                                            extractIntegers_SIZE_TS(return_VALUE_SIZE_Cst_Idf($1,top(stack_name_Routine)),&firstSize,&secondSize);
                                                            if(firstSize<=$3 || $3<0 )
                                                                  semantiqueError("Size of matrice incorrect \n");
                                                            if (cmpt==0)
                                                                  strcpy(TAB_reference,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 
                                                            if (cmpt==1 ) { 
                                                                  
                                                                  strcpy(save_type_operateur,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 
                                                             }
                                                             cmpt++;
                                                            }

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
EXPRESSION_BOOL : EXP            {cmpt=0;} 
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

INST_CALL: idf aff CALL_mc idf par_ouvrante ARG_CALL par_fermante pvg {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"ROUTINE")==0) // premier idf est une VARIABLE
                                                                                   semantiqueError("affectation a une VARIABLE non declare ou afftectation a une fonction\n");
                                                                      CheckRoutineExiste ($4);
                                                                      if(atoi(return_VALUE_SIZE_Cst_Idf($4,top(stack_name_Routine)))!= nbArg) 
                                                                      //signature incorrecte
                                                                                   semantiqueError("Signature de la fonction incorrecte\n");
                                                                       if( strcmp(return_TYPE_Cst_Idf($1,top(stack_name_Routine)),return_TYPE_Cst_Idf($4,top(stack_name_Routine)))){ 
                                                                              if(!strcmp(return_TYPE_Cst_Idf($1,top(stack_name_Routine)),"REAL")){
                                                                                    if(strcmp(return_TYPE_Cst_Idf($4,top(stack_name_Routine)),"INTEGER")){
                                                                                          semantiqueError("Incompatibile types\n");}
                                                                               }else{
                                                                                          semantiqueError("Incompatibile types\n");
                                                                              }
                                                                        }
                                                                      nbArg = 0;}  
;
ARG_CALL : liste_parametres_CALL 
        |                        
; 
liste_parametres_CALL: EXP ver liste_parametres_CALL {nbArg++; cmpt=0; }
                      |EXP                           {nbArg++; cmpt=0; }
;
liste_parametres_Eq: EXP ver liste_parametres_Eq      { cmpt=0; }
                      |EXP                            { cmpt=0; }   
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

