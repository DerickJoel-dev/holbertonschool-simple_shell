#include "main.h"

/**
 * execute - Executes a command
 * @line_input: Line input from the user
 *
 * Return: 0 on success, or -1 on error
 */
int execute(char *line_input)
{
    char **args = tokenize(line_input);
    char *path;
    pid_t pid;
    int status;

    if (args == NULL || args[0] == NULL)
    {
        free(args);
        return (-1);
    }

    path = get_path(args[0]);
    if (path == NULL) /* Command not found */
    {
        fprintf(stderr, "%s: Command not found\n", args[0]);
        free(args);
        return (-1);
    }

    pid = fork();
    if (pid < 0) /* Fork failed */
    {
        perror("Fork error");
        free(args);
        free(path);
        return (-1);
    }
    else if (pid == 0) /* Child process */
    {
        if (execve(path, args, environ) == -1)
        {
            perror("Execve error");
            free(args);
            free(path);
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        wait(&status);
    }

    free(args);
    free(path);
    return (0);
}

