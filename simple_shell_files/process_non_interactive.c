#include "main.h"

/**
 * process_non_interactive - Handles the non-intercative mode of the shell
 *
 * Return: exit status of the last command executed.
 */

int process_non_interactive(void)
{
	char *line_input = NULL;
	size_t bufsize = 0;
	int ex = 0, r;

	while ((r = getline(&line_input, &bufsize, stdin)) != -1)
	{
		ex = process_command(line_input);
	}

	free(line_input);
	return (ex);
}
