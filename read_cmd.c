#include "shell.h"
/**
 * cmd_read - A function that takes parameters from user.
 * @cmd: A pointer to a character buffer to store the user's input.
 * @n: The initial size of the character buffer.
 * @value: A variable to store the result.
 * Return: Access to the read and processed line of text.
 */

char *cmd_read(char *cmd, size_t n, ssize_t value)
{
	cmd = NULL;
	n = 0;
	value = _getline(&cmd, &n, stdin);

	if (value == -1)
	{
		free(cmd);
		printerror();
		exit(EXIT_FAILURE);
	}
	else
	{
		size_t i = 0;

		while (cmd[i])
		{
			if (cmd[i] == '\n')
			{
				cmd[i] = '\0';
			}
			i++;
		}
	}
	return (cmd);
}
