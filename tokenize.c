#include "main.h"

/**
 * tokenize - Splits a string into an array of tokens.
 * @line: The input string to tokenize.
 * Return: Array of tokens (NULL-terminated).
 */
char **tokenize(char *line)
{
    char **tokens = NULL;
    char *token = NULL;
    size_t i = 0, bufsize = 64;

    tokens = malloc(bufsize * sizeof(char *));
    if (!tokens)
        return (NULL);

    token = strtok(line, " \t\n");
    while (token)
    {
        tokens[i++] = token;
        if (i >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
                return (NULL);
        }
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return (tokens);
}

