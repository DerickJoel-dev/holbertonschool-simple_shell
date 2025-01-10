#include "main.h"

extern char **environ; /* Declare the environ variable */

/**
 * find_in_path - Searches for a command in the directories listed in PATH.
 * @command: The command to search for.
 *
 * Return: Full path to the command if found, NULL if not found.
 */
char *find_in_path(char *command)
{
    char *path = NULL, *dir = NULL, *full_path = NULL;
    size_t cmd_len, dir_len;
    int i = 0;

    /* Search for the PATH variable in environ */
    while (environ[i])
    {
        if (_strncmp(environ[i], "PATH=", 5) == 0)
        {
            path = environ[i] + 5; /* Skip "PATH=" */
            break;
        }
        i++;
    }

    if (!path) /* If PATH is not found */
        return (NULL);

    cmd_len = strlen(command);
    path = strdup(path); /* Duplicate PATH to avoid modifying the original */
    dir = strtok(path, ":");

    while (dir)
    {
        dir_len = strlen(dir);
        full_path = malloc(dir_len + cmd_len + 2); /* +2 for '/' and '\0' */
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

/**
 * _strncmp - Custom implementation of strncmp.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes to compare.
 *
 * Return: 0 if strings are equal, non-zero otherwise.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return (s1[i] - s2[i]);
    }

    return (0);
}

