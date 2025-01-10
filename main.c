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
			{
				printf("\n");
				free(line_input);
				exit(EXIT_SUCCESS);
			}
			break;
		}
		if (strcmp(line_input, "exit\n") == 0)
		{
			free(line_input);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(line_input, "env\n") == 0)
		{
			print_env();
			free(line_input);
			continue;
		}

		ex = execute(line_input);
		if (ex == -1)
			perror("Execution Error");
		free(line_input);
	}
	return (ex);
}
