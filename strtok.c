#include"shell.h"
/**
 * _strtok - A function to tokenize a given string.
 * @s: The input string to be tokenized.
 * @d: A pointer.
 * Return: A pointer to the next token found in the input string or Null.
 */

char *_strtok(char s[], const char *d)
{
	static char *token, *end;
	const char *delimr, char *begin;
	int srch_delim = 0;

	if (s != NULL)
	{
		if (_strchr(d, *s) != NULL)
			return (NULL);
		token = s;
		end = s + _strlen(s);
	}
	begin = token;
	if (begin == end)
		return (NULL);

	for (; *token; token++)
	{
		if (token != begin && *token == '\0')
			break;

		for (delimr = d; *delimr; delimr++)
		{
			if (*token == *delimr)
			{
				*token = '\0';
				if (token == begin)
					begin++;
				srch_delim = 1;
				break;
			}
		}
		if (srch_delim == 0 && *token)
			srch_delim = 1;
	}
	if (srch_delim == 0)
	{
		return (NULL);
	}
	return (begin);
}
