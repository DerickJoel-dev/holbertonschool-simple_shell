#include "main.h"

/**
 * tokenize_path - Tokenizes PATH variable
 * @p: the full path
 *
 * Return: array of pointers to path tokens
 */

char **tokenize_path(char *p)
{
	char **buffer; /* Array of pointers to store path tokens */
	int i = 0;
	char *token; /** Temporary token storage */

	buffer = (char **) malloc(sizeof(char *) * 1024);
	if (buffer == NULL)
	{
		perror("error in memory allocation");
		exit(EXIT_FAILURE);
	}
	token = strtok(p, ":");
	while (token != NULL)
	{
		buffer[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	buffer[i] = NULL; /** Making the end of the buffer */
	return (buffer);
}

/**
 * get_path - Gets the path
 * @cmd: The command
 *
 * Return: The full path or NULL (on error)
 */

char *get_path(char *cmd)
{
	char *envp, *copenvp;
	char path[1024];
	char *token;
	struct stat st;

	envp = getenv("PATH");
	if (envp == NULL) /** PATH is not set */
		return (NULL);
	copenvp = strdup(envp);
	token = strtok(copenvp, ":");
	while (token)
	{
		sprintf(path, "%s/%s", token, cmd); /** Construct the full path */
		if (stat(path, &st) == 0) /** Check if the path is valid */
		{
			free(copenvp);
			return (strdup(path));
		}
		token = strtok(NULL, ":"); /** Get the next token */
	}
	free(copenvp);
	return (NULL);
}

/**
 * print_env - Prints the current enviroment
 *
 */

void print_env(void)
{
	char **enviroment = environ; /** Pointer to enviroment variables */

	while (*enviroment != NULL)
	{
		printf("%s\n", *enviroment);
		enviroment++;
	}
}
