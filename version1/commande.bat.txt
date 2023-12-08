flex lexical.l
gcc lex.yy.c -o comp.exe  -lfl 
comp.exe exemple.txt