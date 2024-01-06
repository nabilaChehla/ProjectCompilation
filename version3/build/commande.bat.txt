flex  "../src/lexical.l" -o "../src/lex.yy.c"
bison "../src/syntaxique.y" -d  -o "../src/syntaxique.tab.c" 
gcc -I../include "../src/lex.yy.c" "../src/syntaxique.tab.c" -lfl -ly -o app.exe 