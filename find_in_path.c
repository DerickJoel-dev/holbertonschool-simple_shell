#include "main.h"

/**
 * find_in_path - Searches for a command in the directories listed in PATH.
 * @command: The command to search for.
 *
 * Return: Full path to the command if found, NULL if not found.
 */
char *find_in_path(char *command)
{
    char *path = getenv("PATH");
    char *dir, *full_path;
    size_t cmd_len;

    if (!path || !command)
        return (NULL);

    cmd_len = strlen(command);
    path = strdup(path); /* Duplicate PATH to avoid modifying the original */
    dir = strtok(path, ":");

    while (dir)
    {
        full_path = malloc(strlen(dir) + cmd_len + 2); /* +2 for '/' and '\0' */
        if (!full_path)
        {
            free(path);
            return (NULL);
        }

        sprintf(full_path, "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0) /* Check if command is executable */
        {
            free(path);
            return (full_path);
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path);
    return (NULL);
}

