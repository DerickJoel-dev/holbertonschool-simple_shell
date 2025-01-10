#include "main.h"

/**
 * _trim - Removes leading and trailing spaces from a string
 * @str: The string to trim
 *
 * Return: Pointer to the trimmed string
 */
char *_trim(char *str)
{
    char *end;

    while (*str == ' ')
        str++;

    if (*str == '\0')
        return str;

    end = str + strlen(str) - 1;
    while (end > str && *end == ' ')
        end--;

    *(end + 1) = '\0';

    return str;
}

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, or -1 on error
 */
int main(void)
{
    char *line_input = NULL;
    size_t bufsize = 0;
    ssize_t r;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("simpleshell$ ");

        r = getline(&line_input, &bufsize, stdin);
        if (r == -1)
        {
            free(line_input);
            exit(EXIT_SUCCESS);
        }

        if (line_input[r - 1] == '\n')
            line_input[r - 1] = '\0';

        line_input = _trim(line_input);

        if (line_input[0] == '\0')
        {
            free(line_input);
            line_input = NULL;
            continue;
        }

        if (strcmp(line_input, "exit") == 0)
        {
            free(line_input);
            exit(EXIT_SUCCESS);
        }

        if (execute(line_input) == -1)
            perror("Execution error");

        free(line_input);
        line_input = NULL;
    }
    return (0);
}

