#include "main.h"

/**
 * trim_space - Removes leading and trailing spaces from a string
 * @str: The input string
 *
 * Return: Pointer to the trimmed string
 */
char *trim_space(char *str)
{
    char *end;

    while (*str == ' ')
        str++;

    if (*str == '\0')
        return (str);

    end = str + strlen(str) - 1;
    while (end > str && *end == ' ')
        end--;

    *(end + 1) = '\0';
    return (str);
}

