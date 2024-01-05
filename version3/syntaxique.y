
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts_liste.h"
#include "quad.h"
 extern  nb_ligne;
 extern Col;
 int qc=0;
 extern char fileName[50];
Stack *stack_type;
Stack *stack_value;
Stack *stack_name_Routine ; 
Stack *stack_variable ; 
Stack *stack_BZ;
Stack *stack_deb_cond;
  char code [MAX_CODE_LENGTH];
  char save_type_operateur [MAX_TYPE_LENGTH];
  char op1 [MAX_STRING_SIZE];
  char op2 [MAX_STRING_SIZE];
  char strg[MAX_STRING_SIZE];
  char strg2[MAX_STRING_SIZE];    
  char TAB_reference[MAX_STRING_SIZE];
  char Type_routine[MAX_TYPE_LENGTH];
  char temp[10];
  char value_op[MAX_STRING_SIZE];
  char taille2[MAX_STRING_SIZE];
  char taille1[MAX_STRING_SIZE]; 
  char firstSize;
  char secondSize;
  int nbArg = 0 ; 
  int cmpt= 0;
  bool SiIDF1=false;
  bool SiIDF2=false;
  int nbArg_Write=0 ; 
  int nbArg_Eqv =0 ; 
  int sauv_BR,Fin_inst_cond,tab_dec;
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
                        { traitement_Fin_Routine(stack_name_Routine,stack_value,stack_type);  nbArg = 0;}
           | 
;
fonc: save_name_func par_ouvrante ARG par_fermante DEC INSTRUCTIONS Affectation_fonction ENDR_mc{ check_Affectation_fin_Routine(stack_type,save_type_operateur,&cmpt);}

;
save_name_func: type_fonc ROUTINE_mc idf {push(stack_name_Routine,$3);}
;
Affectation_fonction: idf aff EXP pvg       {Check_Retour_Routine($1, stack_name_Routine);strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",$1);pop(stack_variable);quadr("return",$1,"vide","vide");cmpt=0;}
                    | idf aff character pvg {Check_Retour_Routine($1, stack_name_Routine);
                                             strcpy(save_type_operateur,"CHARACTER");
                                             cmpt=cmpt+2;
                                             quadr(":=",$3,"vide",$1);
                                             quadr("return",$1,"vide","vide");
                                             cmpt =0; 
                                            }
                    | idf aff LOGICAL_VALUE pvg {Check_Retour_Routine($1, stack_name_Routine);
                                             strcpy(save_type_operateur,"LOGICAL");
                                              cmpt=cmpt+2;
                                              strcpy(strg,top(stack_variable));
                                              quadr(":=",strg,"vide",$1);
                                              pop(stack_variable);
                                              quadr("return",$1,"vide","vide");
                                              pop(stack_value);
                                            }
;
type_fonc: type | CHARACTER_mc {push(stack_type, "CHARACTER")  }
;
ARG : liste_parametres {push(stack_value,intToString(nbArg));quadParametre(stack_variable,nbArg);nbArg=0; }
      |                {push(stack_value,"0"); nbArg=0;}
; 
liste_parametres: idf  ver liste_parametres                                                {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));nbArg++;push(stack_variable,$1);initVar($1,stack_name_Routine);}                                      
                | idf par_ouvrante cst_int ver cst_int  par_fermante  ver liste_parametres {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_CODE_Cst_Idf($1,"MATRICE",top(stack_name_Routine));add_Taille_Tab_Mat($1,intToString($3),intToString($5),stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,$1,$3,$5);}
                | idf par_ouvrante cst_int  par_fermante ver liste_parametres              {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_CODE_Cst_Idf($1,"TABLEAU",top(stack_name_Routine));add_Taille_Tab_Mat($1,intToString($3),"0",stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,$1,$3,-1);}
                | idf                                                                      {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));nbArg++;push(stack_variable,$1);initVar($1,stack_name_Routine);}
                | idf par_ouvrante cst_int ver cst_int  par_fermante                       {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_CODE_Cst_Idf($1,"MATRICE",top(stack_name_Routine));add_Taille_Tab_Mat($1,intToString($3),intToString($5),stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,$1,$3,$5);}
                | idf par_ouvrante cst_int  par_fermante                                   {add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_CODE_Cst_Idf($1,"TABLEAU",top(stack_name_Routine));add_Taille_Tab_Mat($1,intToString($3),"0",stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,$1,$3,-1);}
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
DEC_TAB: type idf DIMENSION_mc par_ouvrante EXP LIST_PAR_TAB par_fermante       {if(idf_exist($2,top(stack_name_Routine)))semantiqueError("Double declaration");
                                                                                 //if(strcmp(save_type_operateur,"INTEGER"))semantiqueError("the Size must be an integer");
                                                                                    add_SCOPE_Cst_Idf($2,top(stack_name_Routine));
                                                                                    add_TYPE_Cst_Idf($2,top(stack_type),top(stack_name_Routine));
                                                                                    strcpy(taille1,top(stack_variable));
                                                                                    
                                                                                    add_CODE_Cst_Idf($2,code,top(stack_name_Routine));
                                                                                    Traitement_taille_TAB_MAT($2,taille1,taille2,save_type_operateur,stack_name_Routine,SiIDF1);
                                                                                    pop(stack_type);
                                                                                    ajour_quad(tab_dec,1,taille1);
                                                                                    quadr("ADEC",$2,"vide","vide");
                                                                                    cmpt=0;   
                                                                                    }
        |CHARACTER_mc idf DIMENSION_mc par_ouvrante EXP LIST_PAR_TAB par_fermante   {if(idf_exist($2,top(stack_name_Routine)))semantiqueError("Double declaration");
                                                                                    if(strcmp(save_type_operateur,"INTEGER"))semantiqueError("the Size 2 must be an integer");
                                                                                    add_SCOPE_Cst_Idf($2,top(stack_name_Routine));
                                                                                    add_TYPE_Cst_Idf($2,"CHARACTER",top(stack_name_Routine));
                                                                                    add_CODE_Cst_Idf($2,code,top(stack_name_Routine));
                                                                                    Traitement_taille_TAB_MAT($2,taille1,taille2,save_type_operateur,stack_name_Routine,SiIDF1);
                                                                                    ajour_quad(tab_dec,1,taille1);
                                                                                    quadr("ADEC",$2,"vide","vide");
                                                                                    cmpt=0;
                                                                                    }
;

LIST_PAR_TAB : ver EXP { strcpy(taille2,top(stack_variable));pop(stack_variable); strcpy(code,"MATRICE");if(!checkTaille(taille2) && strcmp(strg,"INTEGER")){ semantiqueError("the size must be an integer");}
 tab_dec=qc; quadr("BOUNDS","",taille2,"vide");} 
              |        { strcpy(code,"TABLEAU");tab_dec=qc;quadr("BOUNDS","","vide","vide");}
              ;
DEC_AFF: aff cst_int  {push(stack_value, intToString($2));push(stack_variable,intToString($2))} 
       | aff cst_real {push(stack_value, floatToString($2));push(stack_variable,floatToString($2)) } 
       | aff  TRUE_mc {push(stack_value, $2);push(stack_variable,$2);  }
       | aff FALSE_mc {push(stack_value, $2);push(stack_variable,$2);  }
;
DEC_CHAR :    idf multip cst_int ver   DEC_CHAR            {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf multip cst_int                           {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf multip cst_int DEC_CHAR_AFF              {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf multip cst_int DEC_CHAR_AFF ver DEC_CHAR {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf                                          {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf ver DEC_CHAR                             {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf DEC_CHAR_AFF                             {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
          |   idf DEC_CHAR_AFF ver   DEC_CHAR              {checkDoubleDeclaration($1,stack_name_Routine);add_SCOPE_Cst_Idf($1,top(stack_name_Routine));add_TYPE_Cst_Idf($1, "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf($1,"VARIABLE",top(stack_name_Routine));}
;

DEC_CHAR_AFF: aff character  {push(stack_value,$2);push(stack_variable,$2);}
;
type:  INTEGER_mc  {push(stack_type, "INTEGER");}
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

Affectation: idf aff EXP pvg             {check_idf_Variable_Existe($1,stack_name_Routine);
                                          checkType_affectation_idf($1,save_type_operateur,stack_name_Routine,cmpt);
                                                
                                                if(cmpt==2) {add_VALUE_Cst_Idf($1,value_op,top(stack_name_Routine));}
                                                strcpy(strg,top(stack_variable));
                                                quadr(":=",strg,"vide",$1);
                                                pop(stack_variable);
                                            
                                                initVar($1,stack_name_Routine);
                                                cmpt=0;
                                          }
            |idf aff character pvg        {check_idf_Variable_Existe($1,stack_name_Routine);
                                           check_Type_char($1,stack_name_Routine);
                                           quadr(":=",$3,"vide",$1);
                                           add_VALUE_Cst_Idf($1,$3,top(stack_name_Routine));
                                          }
            |TAB_PAR aff EXP pvg          {
                                           checkType_affectation_TAB(TAB_reference,save_type_operateur,stack_name_Routine,cmpt);
                                                cmpt=0; 
                                                strcpy(strg,top(stack_variable));
                                                pop(stack_variable);
                                                strcpy(strg2,top(stack_variable));
                                                pop(stack_variable);
                                                quadr(":=",strg,"vide",strg2 );
                                          }                                   
            
            |idf aff LOGICAL_VALUE pvg    {check_idf_Variable_Existe($1,stack_name_Routine);
                                           checkType_affectation_idf_Logical($1,stack_name_Routine);
                                           strcpy(strg,top(stack_variable));
                                           quadr(":=",strg,"vide",$1);
                                           pop(stack_variable);
                                           add_VALUE_Cst_Idf($1,top(stack_value),top(stack_name_Routine));
                                           pop(stack_value);
                                           }

;

Entre_Sortie_INST:  WRITE_mc par_ouvrante SORTIE_MESSAGE par_fermante pvg {quadr("CALL", "WRITE", intToString(nbArg_Write), "vide");nbArg_Write=0; }
                  | READ_mc par_ouvrante idf par_fermante pvg  {        //verifier si c'est le bon idf : 
                                                                  checkIdfRead_Variable_elem($3, stack_name_Routine);
                                                                  // remlir quadruplets
                                                                  quadRead($3);
                                                                  // La variable devient initialise apres la lecture 
                                                                  initVar($3,stack_name_Routine);
                                                                  }
                 | READ_mc par_ouvrante TAB_PAR par_fermante pvg  { //verifier si c'est le bon idf : 
                                                                  checkIdfRead_Variable_Tableau(stack_variable,stack_name_Routine);
                                                                  // remlir quadruplets
                                                                  strcpy(strg, top(stack_variable));
                                                                  quadRead(strg);
                                                                  pop(stack_variable);
                                                                  }
;
SORTIE_MESSAGE :SORTIE_MESSAGE ver char_niv1   {quadArgument(stack_variable);}
               |SORTIE_MESSAGE  ver EXP       { cmpt=0;nbArg_Write++; quadArgument(stack_variable);}
               | char_niv1                    {quadArgument(stack_variable);}
               | EXP                          { cmpt=0; nbArg_Write++;quadArgument(stack_variable);}
;
char_niv4:character {push(stack_variable,$1);nbArg_Write++;}
;
EQUIVALENCE_INST: EQUIVALENCE_mc liste_Equivalance pvg
;
liste_Equivalance:liste_Equivalance ver SUITE_EQUI
                  |SUITE_EQUI                      
;
SUITE_EQUI: par_ouvrante liste_parametres_Eq par_fermante {quadr("CALL","EQUIVALENCE",intToString(nbArg_Eqv),"vide");nbArg_Eqv=0}
;
liste_parametres_Eq:liste_parametres_Eq ver EXP        { cmpt=0; quadArgument(stack_variable);nbArg_Eqv++;}
                    |EXP                              { cmpt=0; quadArgument(stack_variable);nbArg_Eqv++; }   
;
EXP :EXPRESSION {divZero=false; }
;
EXPRESSION:  EXPRESSION plus SUITE_EXPRESSION_1 {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"+",temp);}
           | EXPRESSION moins SUITE_EXPRESSION_1{divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"-",temp);}
           | SUITE_EXPRESSION_1                
;

SUITE_EXPRESSION_1:  SUITE_EXPRESSION_1 multip SUITE_EXPRESSION_2{divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"*",temp);}
                   | SUITE_EXPRESSION_1 divis suiteDiv           {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"/",temp);}
                   | moins SUITE_EXPRESSION_2                    {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,false);quadOpUnaire(stack_variable,"Moins Unaire")}
                   | SUITE_EXPRESSION_2                                       
;
suiteDiv: SUITE_EXPRESSION_2 {checkDivPar0(divZero);}
;
SUITE_EXPRESSION_2:  par_ouvrante EXPRESSION par_fermante {}
                   | cst_int  {if($1==0)divZero=true;else divZero = false ;
                              if (cmpt==0 || cmpt==1){ strcpy(save_type_operateur,"INTEGER"); strcpy(value_op,intToString($1));}
                              if(cmpt==2) strcpy(strg,"INTEGER");
                              cmpt=cmpt+2;
                              strcpy(strg,"INTEGER");
                              SiIDF1=false;
                              push(stack_variable,intToString($1));
                              }     
                   | cst_real {if($1==0)divZero=true;else divZero = false;
                              if (cmpt==0 || cmpt==1){ strcpy(save_type_operateur,"REAL");  strcpy(value_op,floatToString($1));}    
                              if(cmpt==2) strcpy(strg,"REAL"); 
                              cmpt=cmpt+2;
                              SiIDF1=false;
                              push(stack_variable, floatToString($1));
                              }
                   | TAB_PAR  {  divZero = false  } 
                   | idf {
                              check_idf_Variable_Existe($1,stack_name_Routine);
                              checkInit($1,stack_name_Routine); // verifier que la variable est initialisee
                              divZero = activerDivPar0($1,stack_name_Routine);
                              if(cmpt==2) strcpy(strg,return_TYPE_Cst_Idf($1,top(stack_name_Routine)));  
                              if (cmpt==0 || cmpt==1) {strcpy(save_type_operateur,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); strcpy(value_op,return_VALUE_SIZE_Cst_Idf($1,top(stack_name_Routine)));}
                              cmpt=cmpt+2;
                              SiIDF1=true;
                              push(stack_variable,$1);
                            }
                  
;
TAB_PAR: idf par_ouvrante cst_int ver cst_int  par_fermante {if(!idf_exist($1,top(stack_name_Routine)) || strcmp(return_CODE_Cst_Idf($1,top(stack_name_Routine)),"MATRICE")!=0) // idf n'existe pas dans TS ou pas un nom de matrice 
                                                                  semantiqueError("idf n'existe pas dans TS ou n'est pas une MATRICE\n");
                                                             checkSize($1,stack_name_Routine,$3,$5);
                                                            if (cmpt ==0)
                                                              strcpy(TAB_reference,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 

                                                            if (cmpt==1 ) 
                                                               strcpy(save_type_operateur,return_TYPE_Cst_Idf($1,top(stack_name_Routine)));      
                                                             
                                                             cmpt++;
                                                                  Tab_idfInStack_Quad(stack_variable,$1,$3,$5);
                                                            }
      |idf par_ouvrante cst_int  par_fermante              {check_idf_Tableau_Existe($1,stack_name_Routine);
                                                            checkSize( $1, stack_name_Routine,  $3,  0); 
                                                            if (cmpt==0)
                                                                  strcpy(TAB_reference,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 
                                                            if (cmpt==1 ) { 
                                                                  
                                                                  strcpy(save_type_operateur,return_TYPE_Cst_Idf($1,top(stack_name_Routine))); 
                                                             }
                                                             cmpt++;
                                                             Tab_idfInStack_Quad(stack_variable,$1,$3,-1);
                                                            }

;
COND:   COND  OR_mc   SUITE_COND_1                {quadExpression(stack_variable,"OR",temp);}
      | SUITE_COND_1
;
SUITE_COND_1:  SUITE_COND_1  AND_mc  SUITE_COND_2 {quadExpression(stack_variable,"AND",temp);}
             | SUITE_COND_2
;
SUITE_COND_2:   EXPRESSION_BOOL
              | COND_SIMPLE 
;
COND_SIMPLE :EXPRESSION_BOOL  point LT_mc point  EXPRESSION_BOOL {quadExpression(stack_variable,"LT",temp);}
            |EXPRESSION_BOOL  point GT_mc point  EXPRESSION_BOOL {quadExpression(stack_variable,"GT",temp);}
            |EXPRESSION_BOOL  point NE_mc point  EXPRESSION_BOOL {quadExpression(stack_variable,"NE",temp);}
            |EXPRESSION_BOOL  point LE_mc point  EXPRESSION_BOOL {quadExpression(stack_variable,"LE",temp);}
            |EXPRESSION_BOOL  point GE_mc point  EXPRESSION_BOOL {quadExpression(stack_variable,"GE",temp);}
            |EXPRESSION_BOOL  point EQ_mc point  EXPRESSION_BOOL {quadExpression(stack_variable,"EQ",temp);}
;
EXPRESSION_BOOL : EXP                                                          {cmpt=0;} 
                | LOGICAL_VALUE                                                {pop(stack_value);}
                | par_ouvrante COND  OR_mc   SUITE_COND_1 par_fermante         {quadExpression(stack_variable,"OR",temp);}
                | par_ouvrante  SUITE_COND_1  AND_mc  SUITE_COND_2 par_fermante{quadExpression(stack_variable,"AND",temp);} 
                | par_ouvrante COND_SIMPLE par_fermante                                   
                | par_ouvrante LOGICAL_VALUE par_fermante                      {pop(stack_value);}
;
LOGICAL_VALUE: TRUE_mc {push(stack_variable,$1);push(stack_value,$1);}| FALSE_mc{push(stack_variable,$1);push(stack_value,$1);}
;
IF_INST: DEBUT_INST_IF INSTRUCTIONS ENDIF_mc {
                                             ajour_quad(sauv_BR,1,intToString(qc));
						         }

      | DEBUT_IF INSTRUCTIONS ENDIF_mc    {  sprintf(strg,"%d",qc);
                                             ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                             pop(stack_BZ);
						      }
;
DEBUT_INST_IF: DEBUT_IF  INSTRUCTIONS ELSE_mc {sauv_BR=qc;
                                               quadr("BR","","vide","vide");   
                                               ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                               pop(stack_BZ);}
;

DEBUT_IF:  IF_mc par_ouvrante  COND par_fermante THEN_mc {
                                                           push(stack_BZ,intToString(qc));
                                                           quadr("BZ", "",temp, "vide"); }
;




BOUCLE_INST: BOUCLE_INST1 INSTRUCTIONS ENDDO_mc pvg{strcpy(strg,top(stack_deb_cond));
                                                quadr("BR", strg ,"vide", "vide"); 
                                                pop(stack_deb_cond);
                                                ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                                pop(stack_BZ);}
;
BOUCLE_INST1: BOUCLE_INST2 par_ouvrante  COND par_fermante {push(stack_BZ,intToString(qc)); // J'ai laisser le champs 2 vide. Je dois le remplir apres
                                                            quadr("BZ", "",temp, "vide"); }
;
BOUCLE_INST2: DOWHILE_mc  {push(stack_deb_cond,intToString(qc));}
;

INST_CALL: idf aff CALL_mc idf par_ouvrante ARG_CALL par_fermante pvg {
                                                                      check_idf_Aff_Call($3,stack_name_Routine); // verifier qu'il existe + n'est pas une routine
                                                                      CheckRoutineExiste ($4);
                                                                       check_Routine_Signature($4,stack_name_Routine,nbArg);
                                                                      check_TypeRetour_compatible($1,$3,stack_name_Routine);
                                                                      quadr("CALL",$4,intToString(nbArg),"vide");//(call, nomFonc, nbArg, vide )
                                                                       nbArg = 0;
                                                                       initVar($1,stack_name_Routine);
                                                                      }  
;
ARG_CALL : liste_parametres_CALL 
        |                        
; 
liste_parametres_CALL: liste_parametres_CALL ver EXP {nbArg++; cmpt=0;quadArgument(stack_variable); }
                      |EXP                           {nbArg++; cmpt=0;quadArgument(stack_variable);  }
;

char_niv1: char_niv2
;
char_niv2: char_niv3
; 
char_niv3: char_niv4
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
              stack_BZ = initializeStack();
              stack_deb_cond = initializeStack();
              stack_value = initializeStack();
              stack_name_Routine = initializeStack();
              stack_variable = initializeStack();
            yyrestart(fileLex);

              //initialisation
               initList_Cst_Idf();
               initList_Sep_MotCle();
              yyparse(); 
              printf("syntaxe correcte \n");
              displayList_Sep_MotCle();
              displayList_Cst_Idf();
              afficher_qdr();
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
      afficher_qdr();
      exit(EXIT_FAILURE); 
}

