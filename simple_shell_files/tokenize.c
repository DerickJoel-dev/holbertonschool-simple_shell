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

	tokens = (char **) malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("Error in memory allocation");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n\t");
	}
	tokens[i] = NULL;

	return (tokens);
}
