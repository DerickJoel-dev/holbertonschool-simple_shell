#include "main.h"

/**
 * execute - Executes a command
 * @line_input: Line input from the user
 *
 * Return: exit_status (0 on success, or -1 on error)
 */
int execute(char *line_input)
{
	char **args = NULL;
	char *path = NULL;
	int exit_status = 0;

	line_input = clean_quotes(line_input);

	args = tokenize(line_input);
	if (args == NULL)
		return (-1);

	path = resolve_path(args);
	if (path == NULL)
	{
		fprintf(stderr, "./hsh: %s: No such file or directory\n", args[0]);
		free_tokens(args);
		return (-1);
	}

	exit_status = run_command(path, args);

	free_tokens(args);
	free(path);
	return (exit_status);
}

