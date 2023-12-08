
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int nb_ligne = 1;
 int Col = 1;
 char fileName[50];

%}

lettre [a-zA-Z]
chiffre [0-9]
idf {lettre}({lettre}|{chiffre})*
cst_int [+-]?{chiffre}+
cst_real {cst_int}\.{chiffre}+
character \"(\\.|[^"\\])*\"
commantaire %[^\n]*


%%

"PROGRAM" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : PROGRAM\n"); 
}

"END" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : END\n"); 
}
"ROUTINE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ROUTINE\n"); 
}
"ENDR" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ENDR\n"); 
}
"LOGICAL" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : LOGICAL\n");  
}
"TRUE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : TRUE\n");    
}
"FALSE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : FALSE\n");    
} 
"CHARACTER" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : CHARACTER mot clef\n");  
}
"REAL" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : REAL\n");  
}
"INTEGER" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : INTEGER\n");  
}
"DIMENSION" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : DIMENSION\n");  
} 
"READ" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : READ\n");  
}
"WRITE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  WRITE\n");  
}
"IF" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  IF\n");  
}
"THEN" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  THEN\n");    
}
"ELSE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  ELSE\n");  
}
"ENDIF" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  ENDIF\n");   
}
"GT" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  GT\n");   
}  
"GE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  GE\n");    
}  
"EQ" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  EQ\n");  
}  
"NE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  NE\n");   
}  
"LE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  LE\n");  
}  
"LT" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  LT\n");    
} 
"OR" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  OR\n");   
}  
"AND" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  AND\n");  
} 

"DOWHILE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  DOWHILE\n");  
} 
"ENDDO" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  ENDDO\n");  
}
"EQUIVALENCE" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  EQUIVALENCE\n");  
}
"CALL" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  CALL\n");    
}
{idf} {  
    Col= Col + strlen(yytext);
    if (yyleng>10) printf ("WARNING: identificateur trop long a la ligne %d a la colonne %d (%d characters) \n",nb_ligne, Col,strlen(yytext));
    printf("Entite lexicale reconnue : identificateur (%s)\n",yytext); 
}

{cst_real} {
    Col= Col + strlen(yytext);
    if(atof(yytext) >32767.32767 ||  atof(yytext) < -32768.32768){
     printf("Warning :%d real const hors de l'intervale dans File %s, line %d, character %d\n",yytext,fileName,nb_ligne, Col);
    }
    printf("Entite lexicale reconnue : constante real (%s)\n",yytext); 
}

{cst_int} {
    Col= Col + strlen(yytext);
    if(atoi(yytext) >32767 ||  atoi(yytext) < -32768){
     printf("Warning :%d real const hors de l'intervale dans File %s, line %d, character %d\n",yytext,fileName,nb_ligne, Col);
    }

    else
    printf("Entite lexicale reconnue : constante integer (%s)\n",yytext); 
}

{character} {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : character\n"); 
}
"=" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : = \n"); 
}
"+" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : + \n"); 
}
"-" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : - \n"); 
}
"/" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : / \n"); 
}
"*" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : * \n"); 
}
";" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ;\n"); 
}
"," {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ,\n"); 
}
"." {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : .\n"); 
}
"(" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : (\n"); 
}
")" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : %s\n",yytext); 
}
":" {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : :\n"); 
}
{commantaire} {
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : commantaire\n"); 
}
[ \t] Col= Col + strlen(yytext);

\n {
    Col = 1;
    nb_ligne++;
}

. {
    Col = Col + yyleng;
    printf("File %s, line %d, character %d: lexical error: %s\n",fileName ,nb_ligne, Col, yytext);
}


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
            /*
                `yyrestart()' takes one argument, a `FILE *' pointer (which can be nil,
                if you've set up YY_INPUT to scan from a source other than yyin ),
                 and initializes yyin for scanning from that file.*/
            yylex();
            fclose(fileLex); 
             return EXIT_SUCCESS;
        }


    }
    else{
        printf("too much or too littel aruments \n"); 
                return EXIT_FAILURE ; 
    }

}
