#include "shell.h"

/**
 * free_tokens - A function for freeing the memory.
 * @tokens: An array of pointers.
 */

void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		if (tokens[i] != NULL)
		{
			free(tokens[i]);
		}
	}
	free(tokens);
}
