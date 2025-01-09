#include "main.h"

/**
 * process_interactive - Handles the interactive mode of the shell
 *
 * Return: exit status of the last command executed.
 */

int process_interactive(void)
{
	char *line_input = NULL;
	size_t bufsize = 0;
	int ex = 0, r;

	while (1)
	{
		printf("#cisfun$ ");
		signal(SIGINT, signal_handler);

		r = getline(&line_input, &bufsize, stdin);
		if (r == -1)
		{
			if (feof(stdin))
				printf("\n");
			break;
		}

		ex = process_command(line_input);
		free(line_input);
		line_input = NULL;
	}

	free(line_input);
	return (ex);
}
