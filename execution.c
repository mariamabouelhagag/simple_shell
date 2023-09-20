#include "shell.h"
/**
 * sl_srch - search if a string contains a "/" character.
 * @str: The input string to check.
 *
 * Return: True if the string contains a "/", false otherwise.
 */
bool sl_srch(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '/')
		{
			return (true);
		}
	}
	return (false);
}
/**
 * execute_writen_path - function to execute command if writen by path
 * @tokens : an array of pointers represent tokens from command line.
 *
 * Return: execution of command
 */

void execute_writen_path(char **tokens)
{
	if (sl_srch(tokens[0]))
	{
		execve(tokens[0], tokens, NULL);
		free_tokens(tokens);
	}
}

/**
 * execute_cmd - function to execute the command line.
 * @tokens: an array of pointers of tokens to be executed.
 */

void execute_cmd(char **tokens)
{
	char *full_path = NULL;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		printerror();
		free_tokens(tokens);
		return;
	}
	if (pid == 0)
	{
		if (tokens[0] != NULL)
		{
			handel_exit(tokens);
			execute_writen_path(tokens);
			full_path = get_full_path_of_command(tokens[0]);
			execve(full_path, tokens, environ);
			free(full_path);
			free_tokens(tokens);
			printerror();
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
		handel_exit(tokens);
		free_tokens(tokens);
	}
}
