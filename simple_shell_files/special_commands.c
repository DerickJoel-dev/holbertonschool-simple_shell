#include "main.h"

/**
 * handle_special_command - Handles special commands like "exit" and "env"
 * @line_input: User input line
 *
 * Return: 1 if the command was handled, 0 otherwise
 */
int handle_special_command(char *line_input)
{
	if (strcmp(line_input, "exit\n") == 0)
	{
		free(line_input);
		exit(0);
	}

	if (strcmp(line_input, "env\n") == 0)
	{
		int i;

		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (1);
	}

	return (0);
}

