#include "main.h"

/**
 * execute - Executes a command
 * @line_input: Line input from the user
 *
 * Return: 0 on success, or -1 on error
 */
int execute(char *line_input)
{
	char *args[2]; /* Array for command and NULL terminator */
	pid_t pid;
	int status;
	
	args[0] = strtok(line_input, "\n"); /* Remove newline character */
	args[1] = NULL; /* Null-terminate the arguments array */
	
	pid = fork();
	if (pid < 0) /* Fork failed */
	{
	   	perror("fork error");
	   	return (-1);
	}
	else if (pid == 0) /* Child process */
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(&status); /* Wait for child to finish */
	}

	return (0);
}

