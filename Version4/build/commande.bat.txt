flex ../src/lexical.l
bison ../src/syntaxique.y -d
gcc -I../include lex.yy.c syntaxique.tab.c -lfl -ly -o app.exe