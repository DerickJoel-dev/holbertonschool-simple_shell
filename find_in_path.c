#include "main.h"

/**
 * find_in_path - Searches for a command in the directories listed in PATH.
 * @command: The command to search for.
 * Return: Full path to the command if found, or NULL if not found.
 */
char *find_in_path(char *command)
{
    char *path = getenv("PATH");
    char *dir, *full_path;
    size_t cmd_len = strlen(command);

    if (!path)
        return (NULL);

    path = strdup(path); /* Copy PATH to avoid modifying the original */
    dir = strtok(path, ":");

    while (dir)
    {
        full_path = malloc(strlen(dir) + cmd_len + 2);
        sprintf(full_path, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0) /* Check if executable */
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
