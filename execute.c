#include "main.h"

/**
 * execute - Creates a child process to execute a command.
 * @args: Array of arguments for the command.
 */
void execute(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path;

    cmd_path = args[0];
    if (access(cmd_path, X_OK) != 0) /* If not executable directly */
        cmd_path = find_in_path(args[0]);

    if (!cmd_path)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        if (execve(cmd_path, args, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    if (cmd_path != args[0])
        free(cmd_path);
}

