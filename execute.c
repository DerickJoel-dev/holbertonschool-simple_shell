#include "main.h"
/**
 * execute - Executes a command
 * @line_input: Line input from the user
 *
 * Return: exit_stat (0 on success or -1 on error)
*/
int execute(char *line_input)
{
	char **args = NULL;
	char *path = NULL;
	pid_t pid;
	int status, exit_stat = 0;

	args = tokenize(line_input);
	if (args == NULL)
		return (-1); /** Return -1 if tokenization fails */

	if (line_input[0] == '/')
		path = strdup(line_input); /** Use the input as path if it starts with '/' */
	else
		path = get_path(args[0]);
	if (path == NULL) /** Failed to retreive path */
	{
		free_tokens(args);
		return (-1);
	}
	pid = fork(); /** Create a child process */
	if (pid < 0) /** Fork failure */
	{
		free_tokens(args);
		free(path);
		return (-1);
	}
	else if (pid == 0)  /** Child process */
	{
		exit_stat = execve(path, args, environ);
	}
	else  /** Parent process */
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status); /** Get child process exit status */
	}
	free_tokens(args);
	free(path);
	return (exit_stat);
}
