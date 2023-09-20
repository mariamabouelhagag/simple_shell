#include "shell.h"
/**
 * _getenv - A function for retrieving the value
 * of an environment variable by its name.
 * @name: A pointer of the input.
 * Return: Null if the input name is NULL,
 * If the variable is not found return 0.
 */
char *_getenv(const char *name)
{
	int i, a;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		a = 0;
		if (name[a] == environ[i][a])
		{
			while (name[a])
			{
				if (name[a] != environ[i][a])
					break;
				a++;
			}
			if (name[a] == '\0')
			{
				value = (environ[i] + a + 1);
				return (value);
			}
		}
	}
	return (NULL);
}
