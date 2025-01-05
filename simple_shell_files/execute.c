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
	pid_t pid;
	int status, exit_status = 0;

	args = tokenize(line_input);
	if (args == NULL)
		return (-1);

	if (line_input[0] == '/')
		path = strdup(line_input);
	else
		path = get_path(args[0]);

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: %s: No such file or directory\n", args[0]);
		free_tokens(args);
		args = NULL;
		return (-1);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free_tokens(args);
		free(path);
		args = NULL;
		path = NULL;
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("./hsh");
			free_tokens(args);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}

	free_tokens(args);
	free(path);
	args = NULL;
	path = NULL;

	return (exit_status);
}

