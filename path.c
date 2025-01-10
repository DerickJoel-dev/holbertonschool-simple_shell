#include "main.h"

/**
 * tokenize_path - Tokenizes the PATH variable into an array of directories
 * @p: The PATH string to tokenize
 *
 * Return: Array of pointers to the directories in PATH, or NULL on failure
 */
char **tokenize_path(char *p)
{
    char **buffer;
    int i = 0;
    char *token;

    buffer = malloc(sizeof(char *) * 1024);
    if (buffer == NULL)
    {
        perror("Memory allocation error");
        return (NULL);
    }
    token = strtok(p, ":");
    while (token != NULL)
    {
        buffer[i] = strdup(token);
        if (buffer[i] == NULL)
        {
            perror("Memory allocation error");
            free_tokens(buffer);
            return (NULL);
        }
        token = strtok(NULL, ":");
        i++;
    }
    buffer[i] = NULL;
    return (buffer);
}

/**
 * get_path - Retrieves the full path of a command if it exists in PATH
 * @cmd: The command to locate
 *
 * Return: The full path of the command, or NULL if not found
 */
char *get_path(char *cmd)
{
    char *envp, *path_copy, *full_path;
    char **paths;
    struct stat st;
    int i;

    envp = getenv("PATH");
    if (envp == NULL)
        return (NULL);
    path_copy = strdup(envp);
    if (path_copy == NULL)
    {
        perror("Memory allocation error");
        return (NULL);
    }
    paths = tokenize_path(path_copy);
    free(path_copy);
    if (paths == NULL)
        return (NULL);
    for (i = 0; paths[i]; i++)
    {
        full_path = malloc(strlen(paths[i]) + strlen(cmd) + 2);
        if (full_path == NULL)
        {
            perror("Memory allocation error");
            free_tokens(paths);
            return (NULL);
        }
        sprintf(full_path, "%s/%s", paths[i], cmd);
        if (stat(full_path, &st) == 0)
        {
            free_tokens(paths);
            return (full_path);
        }
        free(full_path);
    }
    free_tokens(paths);
    return (NULL);
}

/**
 * print_env - Prints the current environment variables
 */
void print_env(void)
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

