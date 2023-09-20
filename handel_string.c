#include "shell.h"
/**
 * _strlen - A function that calculates the length of string.
 * @str: The string.
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}


/**
 * _strcat - A function that concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}


/**
 * _strchr - Searchs for the first occurrence of a character.
 * @str: The string.
 * @ch: The character.
 * Return: A pointer.
 */
char *_strchr(const char *str, int ch)
{
	char *ptr = NULL;

	while (*str != '\0')
	{
		if (*str == ch)
		{
			ptr = (char *)str;
			break;
		}
		str++;
	}
	return (ptr);
}


/**
 * _strcpy - Copies a source string into a destination string.
 * @cpy: The destination string.
 * @orignal: The source string.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *cpy, const char *orignal)
{
	int i = 0;
	char *cpy_ptr = cpy;
	const char *orignal_ptr = orignal;

	while ((*cpy_ptr++ = *orignal_ptr++) != '\0')
	{
		cpy[i] = orignal[i];
		i++;
	}
	return (cpy);
}


/**
 * _strcmp - A function that compares two strings.
 * @str1: The first string.
 * @str2: The second string.
 * Return: 0 if both strings are equal,
 * or -1 if str1 is shorter than str2,
 * or 1 if str1 is longer than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] < str2[i])
		{
			return (-1);
		}
		else if (str1[i] > str2[i])
		{
			return (1);
		}
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else if (str1[i] == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
