void compatibleTypes(char entite1[], int type, int numLigne)
{
    // type = 1 : int
    // type = 2 : string
    // type = 3 : real

    int posEntite = recherche(entite1);

    if (strcmp(ts[posEntite].TypeEntite, "") == 1)
    {

        if (type == 1)
        {
            if (strcmp(ts[posEntite].TypeEntite, "int") != 0)
            {
                printf("Erreur semantique [ligne %d]: le type de la variable %s n'est pas compatible avec le type int. \n", numLigne, entite1);
            }
        }
        else if (type == 2)
        {
            if (strcmp(ts[posEntite].TypeEntite, "string") != 0)
            {
                printf("Erreur semantique [ligne %d]: le type de la variable %s n'est pas compatible avec le type string. \n", numLigne, entite1);
            }
        }
        else if (type == 3)
        {
            if (strcmp(ts[posEntite].TypeEntite, "real") != 0)
            {
                printf("Erreur semantique [ligne %d]: le type de la variable %s n'est pas compatible avec le type real. \n", numLigne, entite1);
            }
        }
        else
        {
            printf("Erreur semantique [ligne %d]: le type %d n'est pas valide. \n", numLigne, type);
        }
    }
}

void nonDeclaration(char entite[], int numLigne)
{

    int posEntite = recherche(entite);

    if (strcmp(ts[posEntite].TypeEntite, "") == 0)
    {
        printf("Erreur semantique [ligne %d]: l'entite %s n'est pas declaree. \n", numLigne, entite);
    }
}

void doubleDeclaration(char entite[], char type[], int numLigne)
{

    int posEntite = recherche(entite);

    if (strcmp(ts[posEntite].TypeEntite, "") == 0)
    {
        insererType(entite, type);
    }
    else
    {
        /*errur semantique + num ligne de lerreur */
        printf("Erreur semantique [ligne %d]: l'entite %s est deja declaree. \n", numLigne, entite);
    }
}

void maj(char entite[], char type[])
{
    int i;
    for (i = 0; ((i < 1000) && (tab[i].state == 1)) && (strcmp(entite, tab[i].name) != 0); i++)
        ;
    if (i < 1000)

        strcpy(tab[i].type, type);
}