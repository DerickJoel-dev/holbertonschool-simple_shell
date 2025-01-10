#include "main.h"

/**
 * execute - Executes a command with arguments.
 * @args: Array of arguments, including the command.
 *
 * Description: Forks a child process to execute the command
 *              using execve and waits for the child process.
 */
void execute(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        /* Child process: Execute the command */
        if (execve(args[0], args, NULL) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process: Wait for child to complete */
        wait(&status);
    }
}

