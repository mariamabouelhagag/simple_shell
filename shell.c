#include "shell.h"
/**
 * main - The main function of the simple shell.
 * Return: 0
 */

int main(void)
{
	char *cmd = NULL, **tokens = NULL;
	size_t n = 0;
	ssize_t p;

	do {
		p = display_prompt();
		tokens = split_cmd(cmd, n);
		execute_cmd(tokens);
	} while (p);
	return (0);
}
