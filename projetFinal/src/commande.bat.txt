flex lexical.l
bison syntaxique.y -d
gcc -I../include lex.yy.c syntaxique.tab.c -lfl -ly -o app.exe