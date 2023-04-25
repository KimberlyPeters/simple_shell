#include "shell.h"

/**
 * _read_line -  Read command prompt.
 * Return: Returns a pointer to the read line.
 */
char *_read_line(void)
{
	char *input_line = NULL;
	size_t bufsize = 0;
	ssize_t read_result;

	read_result = _getline(&input_line, &bufsize, STDIN_FILENO);

	if (read_result == -1)
	{
		free(input_line);
		return (NULL);
	}

	return (input_line);
}
