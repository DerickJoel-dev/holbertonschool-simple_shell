#include "main.h"

/**
 * execute - Executes a command with arguments.
 * @args: Array of arguments, including the command.
 */
void execute(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path;

    if (strchr(args[0], '/')) /* Command contains '/' */
    {
        if (access(args[0], X_OK) == 0) /* File exists and is executable */
        {
            cmd_path = args[0]; /* Use the provided path */
        }
        else
        {
            fprintf(stderr, "./shell: %s: No such file or directory\n", args[0]);
            return;
        }
    }
    else /* Command does not contain '/', search in PATH */
    {
        cmd_path = find_in_path(args[0]);
        if (!cmd_path)
        {
            fprintf(stderr, "./shell: %s: command not found\n", args[0]);
            return;
        }
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
