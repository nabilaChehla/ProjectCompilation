flex lexical.l
bison syntaxiqueMeli.y -d
gcc lex.yy.c syntaxiqueMeli.tab.c -lfl -ly -o app.exe