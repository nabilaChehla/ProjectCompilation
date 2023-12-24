
%{
   #include "syntaxique.tab.h"
    int nb_ligne =1;
    int  Col = 1;
    char fileName[50];
    extern YYSTYPE yylval;
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
    insert_Sep_MotCle(yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    ECHO ;
    return PROGRAM_mc;
}

"END"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle(yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;
        return END_mc;
}
"ROUTINE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return ROUTINE_mc;
}
"ENDR"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
    return ENDR_mc; 
}
"LOGICAL"     {yylval.str=strdup(yytext);
    insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
    return LOGICAL_mc;  
}
"TRUE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
    return TRUE_mc;     
}
"FALSE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
    return FALSE_mc; 
} 
"CHARACTER"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
    return CHARACTER_mc; 
}
"REAL"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
        return REAL_mc; 
}
"INTEGER"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return INTEGER_mc; 
}
"DIMENSION"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return DIMENSION_mc;  
} 
"READ"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return READ_mc; 
}
"WRITE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return WRITE_mc;  
}
"IF"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return IF_mc;  
}
"THEN"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return THEN_mc;  
}
"ELSE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return ELSE_mc;  
}
"ENDIF"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return ENDIF_mc; 
}
"GT"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return GT_mc; 
}  
"GE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return GE_mc;   
}  
"EQ"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
        ECHO ;        
            return EQ_mc; 
}  
"NE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return NE_mc;  
}  
"LE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return LE_mc; 
}  
"LT"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return LT_mc;   
} 
".OR."     {yylval.str=strdup(yytext);
            insert_Sep_MotCle( yytext,"Mot Clef");
            Col= Col + strlen(yytext);
            ECHO ;        
            return OR_mc; 
}  
".AND."     {yylval.str=strdup(yytext);
            insert_Sep_MotCle( yytext,"Mot Clef");
            Col= Col + strlen(yytext);
            ECHO ;        
            return AND_mc; 
} 

"DOWHILE"     {yylval.str=strdup(yytext);
               insert_Sep_MotCle( yytext,"Mot Clef");
               Col= Col + strlen(yytext);
               ECHO ;        
               return DOWHILE_mc; 
} 
"ENDDO"     {yylval.str=strdup(yytext);
            insert_Sep_MotCle( yytext,"Mot Clef");
            Col= Col + strlen(yytext);
            ECHO ;        
            return ENDDO_mc; 
}
"EQUIVALENCE"     {yylval.str=strdup(yytext);
                  insert_Sep_MotCle( yytext,"Mot Clef");
                  Col= Col + strlen(yytext);
                  ECHO ;        
                  return EQUIVALENCE_mc; 
}
"CALL"     {yylval.str=strdup(yytext);
            insert_Sep_MotCle( yytext,"Mot Clef");
            Col= Col + strlen(yytext);
            ECHO ;        
            return CALL_mc; 
}

{idf}  {yylval.str=strdup(yytext);
        Col= Col + strlen(yytext);
        ECHO ; 
        if (yyleng>10) printf ("\nWARNING: identificateur trop long a la ligne %d a la colonne %d (%d characters) \n",nb_ligne, Col,strlen(yytext));
        insert_Cst_Idf(yytext,"","","0");        
        return idf;
}


{cst_real} {
        yylval.reel=atof(yytext);
        Col= Col + strlen(yytext);
        if(atof(yytext) >32767.32767 ||  atof(yytext) < -32768.32768){
        ECHO ; 
        printf("\nWarning :%s real const hors de l'intervale dans File %s, line %d, character %d\n",yytext,fileName,nb_ligne, Col);
        insert_Cst_Idf(yytext,"REAL","cst_real","0"); 
        return cst_real;

    }
    else{
        insert_Cst_Idf(yytext,"REAL","cst_real","0"); 
        ECHO ;        
        return cst_real;
    }

}

{cst_int} {
    yylval.entier=atoi(yytext);
    Col= Col + strlen(yytext);
    if(atoi(yytext) >32767 ||  atoi(yytext) < -32768) {
        ECHO ; 
        printf("\nWarning :%d real const hors de l'intervale dans File %s, line %d, character %d\n",yytext,fileName,nb_ligne, Col);
    }else{
        insert_Cst_Idf(yytext,"INTEGER","cst_int","0"); 
        ECHO ;        
        return cst_int;
    }

}
{character}     {yylval.str=strdup(yytext);
                Col= Col + strlen(yytext);
                ECHO;        
                return character;
}
"="     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return aff;
}
"+"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return plus;
}
"-"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return moins;
}
"/"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return divis;
}
"*"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO;        
        return multip;
}
";"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return pvg;
}
","     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return ver;
}
"."     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return point;
}
"("     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return par_ouvrante;
}
")"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return par_fermante;
}
":"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
        Col= Col + strlen(yytext);
        ECHO ;        
        return points_sup;
}
{commantaire} {
    Col= Col + strlen(yytext);
        ECHO ;        
}
[ \t] {Col= Col + strlen(yytext);
        ECHO;
}


\n {
    Col = 1;
    nb_ligne++;
    ECHO;
}

. {
    Col = Col + yyleng;
    printf("\nFile %s, line %d, character %d: lexical error: %s\n",fileName ,nb_ligne, Col, yytext);
}



