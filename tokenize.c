#include "main.h"

/**
 * tokenize - Splits the line input into tokens
 * @line: The line input
 *
 * Return: The array of tokens
 */
char **tokenize(char *line)
{
    char **tokens = NULL;
    char *token;
    int i = 0;

    tokens = malloc(sizeof(char *) * 1024);
    if (tokens == NULL)
    {
        perror("Error in memory allocation");
        return (NULL);
    }

    token = strtok(line, " \n\t");
    while (token != NULL)
    {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL)
        {
            perror("Error in strdup");
            free(tokens);
            return (NULL);
        }
        i++;
        token = strtok(NULL, " \n\t");
    }
    tokens[i] = NULL;

    return (tokens);
}

