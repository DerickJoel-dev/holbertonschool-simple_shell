#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 (on success) or -1 (on error)
*/

int main(void)
{
	char *line_input = NULL;
	int ex = 0, r;
	size_t bufsize = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleshell$ ");

		signal(SIGINT, signal_handler);

		r = getline(&line_input, &bufsize, stdin);
		if (r == -1)
		{
			if (feof(stdin))
				printf("\n");
			break;
		}
		if (line_input[0] == '\n')
		{
			free(line_input);
			line_input = NULL;
			continue;
		}

		if (handle_special_command(line_input))
		{
			free(line_input);
			line_input = NULL;
			continue;
		}

		ex = execute(line_input);
		free(line_input);
		line_input = NULL;
	}

	free(line_input);
	return (ex);
}
