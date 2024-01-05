#include <stdio.h>
#include <string.h>

int contains_parentheses(const char *input_string)
{
    return strchr(input_string, '(') != NULL && strchr(input_string, ')') != NULL;
}

int main()
{
    char my_string[] = "This is a (sample) string";

    if (contains_parentheses(my_string))
    {
        printf("The string contains parentheses.\n");
    }
    else
    {
        printf("The string does not contain parentheses.\n");
    }

    return 0;
}
