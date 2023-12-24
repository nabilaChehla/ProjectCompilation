#include <stdio.h>

void extractIntegers_SIZE_TS(const char *sizeTS, int *firstSize, int *secondSize)
{
    // Use sscanf to extract two integers separated by '|'
    if (sscanf(sizeTS, " %d | %d", firstSize, secondSize) != 2)
    {
        // Handle error, if the format doesn't match
        printf("Error: Invalid sizeTS format!\n");
    }
}

int main()
{
    // Example usage
    const char *inputString = " 564121 | 0";
    int firstInt, secondInt;

    // Call the function to extract integers
    extractIntegers_SIZE_TS(inputString, &firstInt, &secondInt);

    // Print the extracted integers
    printf("firstSize Integer: %d\n", firstInt);
    printf("secondSize Integer: %d\n", secondInt);

    return 0;
}
