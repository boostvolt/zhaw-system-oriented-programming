//
// Created by Jan Kott on 27.02.2024.
//
#include <stdio.h>

int main()
{
    int charCount = 0;
    int wordCount = 0;
    int c, lastChar = ' '; // int to store EOF and other characters

    printf("Enter a sequence: ");
    while ((c = getchar()) != '\n')
    {
        charCount++;
        if ((c == ' ' || c == '\t') && (lastChar != ' ' && lastChar != '\t'))
        {
            wordCount++;
        }
        lastChar = c;
    }

    if (lastChar != ' ' && lastChar != '\t')
    {
        wordCount++;
    }

    printf("Character count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);

    return 0;
}