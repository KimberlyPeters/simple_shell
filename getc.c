#include "shell.h"

/**
 * _my_getc - Reads a text file and returns the next character from input
 *
 * Return: Next character from input, or EOF on end-of-file or error
 */
int _my_getc(void)
{
	char buffer[1];
	char *chr_ptr;
	int bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, 1);
	if (bytes_read > 0)
	{
		chr_ptr = buffer;
		return (*chr_ptr);
	}

	if (bytes_read == -1)
	{
		return (0);
	}

	return (EOF);
}
