#include "main.h"

/**
 * process_command - processes and executes a single command
 * @line_input: User input command.
 *
 * Return: exit status of the command
 */

int process_command(char *line_input)
{
	int ex = 0;

	if (line_input[0] == '\n')
		return (0);

	if (handle_special_command(line_input))
		return (0);

	ex = execute(line_input);
	return (ex);
}
