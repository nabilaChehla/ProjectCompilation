#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *extractTableName(const char *input)
{
    // Find the opening parenthesis
    const char *openParen = strchr(input, '(');

    // Check if the opening parenthesis is found
    if (openParen != NULL)
    {
        // Calculate the length of the table name
        size_t length = openParen - input;

        // Allocate memory for the table name
        char *tableName = (char *)malloc(length + 1);

        // Copy the table name into the allocated memory
        strncpy(tableName, input, length);
        tableName[length] = '\0'; // Null-terminate the string

        return tableName;
    }
    else
    {
        // Return NULL if the opening parenthesis is not found
        return NULL;
    }
}

int main()
{
    const char *input = "taiouyutyb(10)";
    char *tableName = extractTableName(input);

    if (tableName != NULL)
    {
        printf("Table name: %s\n", tableName);

        // Don't forget to free the allocated memory
        free(tableName);
    }
    else
    {
        printf("Invalid input format\n");
    }

    return 0;
}
