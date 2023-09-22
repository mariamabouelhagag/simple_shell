#include "shell.h"
/**
 * printerror - is a function to print the approprait error message.
 *
 */

void printerror(void)
{
	if (errno == ENOENT)
	{
		write(STDERR_FILENO, "No such file or directory\n", 26);
	}
	else if (errno == EINVAL)
	{
		write(STDERR_FILENO, "Invalid argument\n", 17);
	}
	else if (errno == ENOMEM)
	{
		write(STDERR_FILENO, "Out of memory\n", 14);
	}
	else
	{
		write(STDERR_FILENO, "Unknown error\n", 14);
	}
}
