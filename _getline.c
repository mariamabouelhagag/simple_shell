#include "shell.h"
/**
 * _getc - reads a single character from standard input
 * @stream : voided prameter.
 *
 * Return:
 *   -1 if an error occurs,EOF if the end of file.
 */

int _getc(FILE * stream __attribute__((unused)))
{
	char c;
	ssize_t bytread = read(STDIN_FILENO, &c, 1);

	if (bytread == -1)
	{
		return (-1);
	}
	else if (bytread == 0)
	{
		return (EOF);
	}
	else
	{
		return ((int) c);
	}
}

/**
 * _getline - reads a line from a file stream and stores it.
 *
 * @line: pointer to the string where the line will be stored
 * @n: pointer to the size of the allocated memory for the line
 * @stream: pointer to the file stream to read from
 *
 * Return:
 *   -1 if an error occurs.
 */

ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	ssize_t len = 0, i = 0;
	int c;
	char *new_line;

	if (line == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	while ((c = _getc(stream)) != '\n' && c != EOF)
	{
		if ((size_t)(len + 1) >= *n)
		{
			*n = (*n == 0) ? 1 : *n * 2;
			new_line = malloc((*n) * sizeof(char));
			if (new_line == NULL)
			{
				free(new_line);
				free(*line);
				return (-1);
			}
			for (i = 0; i < len; i++)
			{
				new_line[i] = (*line)[i];
			}
			free(*line);
			*line = new_line;
		}
		(*line)[len++] = c;
	}
	if (len == 0 && c == EOF)
	{
		return (-1);
		free(*line);
	}
	(*line)[len] = '\0';
	return (len);
}
