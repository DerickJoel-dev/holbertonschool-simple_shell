#include "main.h"

/**
 * run_command - Forks and executes a command
 * @path: Resolved path of the command
 * @args: Tokenized command arguments
 *
 * Return: Exit status of the command
 */
int run_command(char *path, char **args)
{
	pid_t pid;
	int status, exit_status = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}

	return (exit_status);
}

