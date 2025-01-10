#include "main.h"
#include <limits.h>

/**
 * execute - Executes a command with arguments.
 * @args: Array of arguments, including the command.
 */
void execute(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path = NULL;
    char resolved_path[PATH_MAX];

    if (args[0][0] == '~') /* Expand '~' to HOME directory */
    {
        char *expanded_path = expand_tilde(args[0]);
        if (expanded_path)
        {
            free(args[0]);
            args[0] = expanded_path;
        }
    }

    if (strchr(args[0], '/')) /* Command contains '/' */
    {
        if (realpath(args[0], resolved_path) != NULL && access(resolved_path, X_OK) == 0)
        {
            cmd_path = strdup(resolved_path);
        }
        else
        {
            fprintf(stderr, "./shell: %s: No such file or directory\n", args[0]);
            return;
        }
    }
    else /* Command does not contain '/', search in PATH */
    {
        char *path_var = getenv("PATH");
        if (!path_var || strlen(path_var) == 0) /* PATH is empty or undefined */
        {
            fprintf(stderr, "./shell: %s: command not found\n", args[0]);
            return;
        }
        cmd_path = find_in_path(args[0]);
    }

    if (!cmd_path) /* Command not found */
    {
        fprintf(stderr, "./shell: %s: command not found\n", args[0]);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) /* Child process */
    {
        if (execve(cmd_path, args, NULL) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        wait(&status);
    }

    if (cmd_path != args[0]) /* Free memory if cmd_path was dynamically allocated */
        free(cmd_path);
}

