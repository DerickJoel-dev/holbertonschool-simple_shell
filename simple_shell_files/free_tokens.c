#include "main.h"
/**
 * free_tokens - Frees the array of tokens
 * @tokens: tokens array
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
