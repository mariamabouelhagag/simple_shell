#include "shell.h"

/**
 * split_cmd - Splits a given command string into individual tokens.
 * @cmd: A pointer to a character buffer to store the user's input.
 * @n: The initial size of the character buffer.
 * Return: The array of tokens.
 */

char **split_cmd(char *cmd, size_t n)
{
	char *line, *line_copy, *token, **tokens;
	char *delim = " \n";
	ssize_t value = 0;
	int num_tokens = 0, i = 0;

	line = cmd_read(cmd, n, value);
	line_copy = malloc((_strlen(line) + 1) * sizeof(char));
	_strcpy(line_copy, line);
	token = strtok(line_copy, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
		tokens = malloc((num_tokens + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			printerror();
			free(cmd);
			free(line);
			free(line_copy);
			exit(EXIT_FAILURE);
		}
		token = strtok(line, delim);
		while (token != NULL)
		{
			tokens[i] = malloc((_strlen(token) + 1) * sizeof(char));
			_strcpy(tokens[i], token);
			i++;
			token = strtok(NULL, delim);
		}
		tokens[i] = NULL;
		free(cmd);
		free(token);
		free(line);
		free(line_copy);
		return (tokens);
}
