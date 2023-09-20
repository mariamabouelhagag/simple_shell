#include "shell.h"

/**
 * get_full_path_of_command - Find the full path of an executable command.
 * @command: A pointer that points to a constant character.
 * Return: The full path of the command if it's found.
 */
char *get_full_path_of_command(const char *command)
{
	const char *path = _getenv("PATH");
	char *path_copy = malloc(_strlen(path) + 1);
	char *dir = NULL;

	if (path_copy == NULL)
	{
		printerror();
		free(path_copy);
		return (NULL);
	}
	_strcpy(path_copy, path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		size_t dir_len = _strlen(dir);
		size_t command_len = _strlen(command);
		struct stat file_stat;
		char *full_path = malloc(dir_len + 1 + command_len + 1);

		if (full_path == NULL)
		{
			printerror();
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (stat(full_path, &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
