#include "shell.h"
/**
 * display_prompt - A function that displays a prompt for user.
 *
 * Return: 0 if the prompt is displayed,and -1 if there is an error
 */

ssize_t display_prompt(void)
{
	ssize_t value = 0;

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		value = write(STDOUT_FILENO, "$ ", 2);
		if (value == -1)
		{
			printerror();
			exit(EXIT_FAILURE);
		}
	}
	return (value);
}
