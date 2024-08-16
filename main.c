/*
C How to Program, 9th Global Edition (Deitel Paul, Deitel Harvey) (Z-Library)
8.24 (Strings Ending with "tion") Write a program that reads a series of strings and
prints only those that end with the letters "tion".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main()
{
    char buffer[SIZE];
    char *delimiter = " ";

    fgets(buffer, SIZE, stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    char *token = strtok(buffer, delimiter);

    while (token != NULL)
    {
        if (strlen(token) < 4)
        {
            continue;
        }

        char *possiblyWord = strrchr(token, 't');

        if (possiblyWord != NULL && strcmp(possiblyWord, "tion") == 0)
        {
            printf("%s\n", token);
        }

        token = strtok(NULL, delimiter);
    }
}