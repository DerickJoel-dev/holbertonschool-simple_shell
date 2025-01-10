#include "main.h"

/**
 * expand_tilde - Expands '~' to the value of the HOME environment variable.
 * @path: The input path that may contain '~'.
 *
 * Return: A newly allocated string with the expanded path, or NULL on failure.
 */
char *expand_tilde(char *path)
{
    char *expanded_path;
    if (path[0] == '~') /* Check if path starts with '~' */
    {
        char *home = getenv("HOME");
        if (!home)
            return NULL;

        expanded_path = malloc(strlen(home) + strlen(path));
        if (!expanded_path)
            return NULL;

        sprintf(expanded_path, "%s%s", home, path + 1);
        return expanded_path;
    }
    return strdup(path); /* Return a copy if no '~' is found */
}
