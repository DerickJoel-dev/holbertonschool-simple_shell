#include "main.h"
#include <sys/stat.h>

/**
 * execute - Executes a command
 * @command: Command to execute
 *
 * Return: 0 on success, or -1 on error
 */
int execute(char *command)
{
    char *args[2];
    struct stat st;
    pid_t pid;
    int status;

    args[0] = command;
    args[1] = NULL;

    /* Cambio: Verificación de existencia y permisos */
    if (stat(command, &st) == -1 || !(st.st_mode & S_IXUSR))
    {
        fprintf(stderr, "%s: No such file or directory\n", command);
        return (-1);
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return (-1);
    }
    else if (pid == 0)
    {
        if (execve(args[0], args, environ) == -1)
        {
            perror("execve error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    return (0);
}

