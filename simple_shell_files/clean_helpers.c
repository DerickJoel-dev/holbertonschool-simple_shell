#include "main.h"

/**
 * clean_quotes - Removes surrounding quotes from the input
 * @line_input: Line input from the user
 *
 * Return: Pointer to cleaned input
 */
char *clean_quotes(char *line_input)
{
	if ((line_input[0] == '"' || line_input[0] == '\'') &&
		line_input[strlen(line_input) - 1] == line_input[0])
	{
		line_input[strlen(line_input) - 1] = '\0';
		line_input++;
	}
	return (line_input);
}

