
%{
   #include "syntaxiqueMeli.tab.h"
    extern nb_ligne ;
    extern Col ;
    extern fileName ;
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
    printf("Entite lexicale reconnue : PROGRAM\n"); 
    return PROGRAM_mc;
}

"END"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle(yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : END\n"); 
        return END_mc;
}
"ROUTINE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ROUTINE\n"); 
        return ROUTINE_mc;
}
"ENDR"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ENDR\n");
    return ENDR_mc; 
}
"LOGICAL"     {yylval.str=strdup(yytext);
    insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : LOGICAL\n");  
    return LOGICAL_mc;  
}
"TRUE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : TRUE\n"); 
    return TRUE_mc;     
}
"FALSE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : FALSE\n");    
    return FALSE_mc; 
} 
"CHARACTER"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : CHARACTER mot clef\n");  
    return CHARACTER_mc; 
}
"REAL"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : REAL\n");  
        return REAL_mc; 
}
"INTEGER"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : INTEGER\n");  
            return INTEGER_mc; 
}
"DIMENSION"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : DIMENSION\n"); 
            return DIMENSION_mc;  
} 
"READ"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : READ\n");  
            return READ_mc; 
}
"WRITE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  WRITE\n"); 
            return WRITE_mc;  
}
"IF"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  IF\n"); 
            return IF_mc;  
}
"THEN"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  THEN\n");   
            return THEN_mc;  
}
"ELSE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  ELSE\n"); 
            return ELSE_mc;  
}
"ENDIF"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  ENDIF\n");   
            return ENDIF_mc; 
}
"GT"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  GT\n");   
            return GT_mc; 
}  
"GE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  GE\n");  
            return GE_mc;   
}  
"EQ"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  EQ\n");  
            return EQ_mc; 
}  
"NE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  NE\n");  
            return NE_mc;  
}  
"LE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  LE\n");  
            return LE_mc; 
}  
"LT"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  LT\n");  
            return LT_mc;   
} 
".OR."     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  OR\n");   
            return OR_mc; 
}  
".AND."     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  AND\n");  
            return AND_mc; 
} 

"DOWHILE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  DOWHILE\n");  
            return DOWHILE_mc; 
} 
"ENDDO"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  ENDDO\n");  
            return ENDDO_mc; 
}
"EQUIVALENCE"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  EQUIVALENCE\n");  
            return EQUIVALENCE_mc; 
}
"CALL"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue :  CALL\n");    
            return CALL_mc; 
}

{idf}  {yylval.str=strdup(yytext);
    Col= Col + strlen(yytext);
    if (yyleng>10) printf ("WARNING: identificateur trop long a la ligne %d a la colonne %d (%d characters) \n",nb_ligne, Col,strlen(yytext));
    insert_Cst_Idf(yytext,"","idf","0"); 
    printf("Entite lexicale reconnue : identificateur (%s)\n",yytext); 
    return idf;
}


{cst_real} {
        yylval.reel=atof(yytext);
    Col= Col + strlen(yytext);
    if(atof(yytext) >32767.32767 ||  atof(yytext) < -32768.32768){
     printf("Warning :%d real const hors de l'intervale dans File %s, line %d, character %d\n",yytext,fileName,nb_ligne, Col);
    }
    else{
     insert_Cst_Idf(yytext,"REAL","cst_real","0"); 
     printf("Entite lexicale reconnue : constante real (%s)\n",yytext); 
        return cst_real;
    }

}

{cst_int} {
     yylval.entier=atoi(yytext);
    Col= Col + strlen(yytext);
    if(atoi(yytext) >32767 ||  atoi(yytext) < -32768) {
     printf("Warning :%d real const hors de l'intervale dans File %s, line %d, character %d\n",yytext,fileName,nb_ligne, Col);
    }else{
     insert_Cst_Idf(yytext,"INTEGER","cst_int","0"); 
     printf("Entite lexicale reconnue : constante integer (%s)\n",yytext); 
                 return cst_int;
    }

}
{character}     {yylval.str=strdup(yytext);
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : character\n"); 
        return character;
}
"="     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : = \n"); 
        return aff;
}
"+"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : + \n"); 
        return plus;
}
"-"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : - \n"); 
        return moins;
}
"/"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : / \n"); 
        return divis;
}
"*"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : * \n"); 
        return multip;
}
";"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ;\n"); 
    return pvg;
}
","     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : ,\n"); 
    return ver;
}
"."     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : .\n"); 
        return point;
}
"("     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : (\n"); 
        return par_ouvrante;
}
")"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : %s\n",yytext); 
        return par_fermante;
}
":"     {yylval.str=strdup(yytext);
        insert_Sep_MotCle( yytext,"Mot Clef");
    Col= Col + strlen(yytext);
    printf("Entite lexicale reconnue : :\n"); 
        return points_sup;
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



