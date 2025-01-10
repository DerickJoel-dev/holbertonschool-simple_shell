#include "main.h"

/**
 * execute - Executes a command
 * @command: Command to execute
 *
 * Return: 0 on success, or -1 on error
 */
int execute(char *command)
{
    char *args[2];
    pid_t pid;
    int status;

    args[0] = command; /* Pass the command */
    args[1] = NULL;    /* Null-terminate the arguments array */

    pid = fork(); /* Fork a child process */
    if (pid < 0)
    {
        perror("fork error");
        return (-1);
    }
    else if (pid == 0) /* Child process */
    {
        if (execve(args[0], args, environ) == -1)
        {
            perror("execve error");
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        wait(&status); /* Wait for child to finish */
    }

    return (0);
}

