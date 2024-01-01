
typedef struct qdr
{

  char oper[100];
  char op1[100];
  char op2[100];
  char res[100];

} qdr;
qdr quad[1000];
extern int qc;
extern int actTemp;
void quadr(char opr[], char op1[], char op2[], char res[])
{

  strcpy(quad[qc].oper, opr);
  strcpy(quad[qc].op1, op1);
  strcpy(quad[qc].op2, op2);
  strcpy(quad[qc].res, res);

  qc++;
}

void ajour_quad(int num_quad, int colon_quad, char val[])
{
  if (colon_quad == 0)
    strcpy(quad[num_quad].oper, val);
  else if (colon_quad == 1)
    strcpy(quad[num_quad].op1, val);
  else if (colon_quad == 2)
    strcpy(quad[num_quad].op2, val);
  else if (colon_quad == 3)
    strcpy(quad[num_quad].res, val);
}

void afficher_qdr()
{
  printf("*********************Les Quadruplets***********************\n");

  int i;

  for (i = 0; i < qc; i++)
  {

    printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
    printf("\n--------------------------------------------------------\n");
  }
}

void quadExpression(Stack *stack_variable, char opr[], char op1[MAX_STRING_SIZE], char op2[MAX_STRING_SIZE])
{
  char temp[10];
  strcpy(temp, "temp");
  strcpy(op2, top(stack_variable));
  pop(stack_variable);
  strcpy(op1, top(stack_variable));
  pop(stack_variable);
  strcat(temp, intToString(actTemp));
  actTemp++;
  quadr(opr, op1, op2, temp);
  push(stack_variable, temp);
}

void Tab_idfInStack_Quad(Stack *stack_variable, const char idf[MAX_NAME_LENGTH], int taille1, int taille2)
{
  char SaveTabIdf[MAX_STRING_SIZE];
  strcpy(SaveTabIdf, idf);
  strcat(SaveTabIdf, "(");
  strcat(SaveTabIdf, intToString(taille1));
  if (taille2 != -1)
  {
    strcat(SaveTabIdf, ",");
    strcat(SaveTabIdf, intToString(taille2));
  }
  strcat(SaveTabIdf, ")");

  push(stack_variable, SaveTabIdf);
}
void quadParametre(Stack *stack_variable, int nbParametres)
{
  while (nbParametres > 0)
  {
    char strg[MAX_STRING_SIZE];
    strcpy(strg, top(stack_variable));
    quadr("Parametre", strg, "vide", "vide");
    pop(stack_variable);
    nbParametres--;
  }
}
void quadArgument(Stack *stack_variable)
{
  char strg[MAX_STRING_SIZE];
  strcpy(strg, top(stack_variable));
  quadr("Argument", strg, "vide", "vide");
  pop(stack_variable);
}
