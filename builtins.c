#include "shell.h"

/**
 * _unsetenv - A function to unset an environment variable.
 * @cm: The name of the environment variable.
 * Return: 0 if the variable is successfully unset
 * and -1 if there is an error or if the input is invalid.
 */

int _unsetenv(const char *cm)
{
	int a = 0, i = 0;
	size_t len;

	if (cm == NULL || cm[0] == '\0' || _strchr(cm, '=') != NULL)
	{
		return (-1);
	}
	len = _strlen(cm);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], cm) == 0 && environ[i][len] == '=')
		{
			for (a = i; environ[a] != NULL; a++)
			{
				environ[a] = environ[a + 1];
			}
			break;
		}
	}
	return (0);
}

/**
 * _setenv - A function to set an environment variable.
 * @cm: The name of the environment variable.
 * @value: The value of the environment variable.
 */
void _setenv(const char *cm, const char *value)
{
	int i = 0;
	size_t cm_len = _strlen(cm);
	size_t value_len = _strlen(value);
	char *env_var = malloc(cm_len + value_len + 2);

	_strcpy(env_var, cm);
	env_var[cm_len] = '=';
	_strcpy(env_var + cm_len + 1, value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], cm) == 0 && environ[i][cm_len] == '=')
		{
			environ[i] = env_var;
			break;
		}
	}
	if (environ[i] == NULL)
	{
		environ[i] = env_var;
		environ[i + 1] = NULL;
	}
}


/**
 * handel_exit - A function to handel the "exit" command.
 * @tokens: an array of pointers.
 */
void handel_exit(char **tokens)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		exit(98);
		free_tokens(tokens);
	}
}
