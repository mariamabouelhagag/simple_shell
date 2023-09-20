#include "shell.h"
/**
 * printerror - is a function to print the approprait error message.
 *
 */

void printerror(void)
{
	if (errno == ENOENT)
	{
		perror("No such file or directory");
	}
	else if (errno == EINVAL)
	{
		perror("Invalid argument");
	}
	else if (errno == ENOMEM)
	{
		perror("Out of memory");
	}
	else
	{
		perror("Unknown error");
	}
}
