#include "main.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0 on successful exit.
 */
int main(void)
{
    char *line = NULL, **args = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            break;
        }

        args = tokenize(line);
        if (args[0])
        {
            if (strcmp(args[0], "exit") == 0)
            {
                free(args);
                free(line);
                exit(0);
            }
            execute(args);
        }

        free(args);
    }

    return (0);
}

