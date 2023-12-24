flex lexical.l
bison syntaxique.y -d
gcc lex.yy.c syntaxique.tab.c -lfl -ly -o app.exe