#include "main.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, or -1 on error
 */
int main(void)
{
	char *line_input = NULL;
	size_t bufsize = 0;
	ssize_t r;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleshell$ ");

		r = getline(&line_input, &bufsize, stdin);
		if (r == -1) /** handles ctrl+D */
		{
			free(line_input);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(line_input, "exit\n") == 0) /** handle exit */
		{
			free(line_input);
			exit(EXIT_SUCCESS);
		}
		if (execute(line_input) == -1)
			perror("Execution error");

		free(line_input);
		line_input = NULL;
	}
	return (0);
}
