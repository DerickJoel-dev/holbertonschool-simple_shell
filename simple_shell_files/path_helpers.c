#include "main.h"

/**
 * resolve_path - Resolves the full path of a command
 * @args: Tokenized command arguments
 *
 * Return: Pointer to the resolved path, or NULL on failure
 */
char *resolve_path(char **args)
{
	if (args[0][0] == '/')
		return (strdup(args[0]));
	return (get_path(args[0]));
}

