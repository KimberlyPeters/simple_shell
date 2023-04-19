#include "shell.h"

/**
 * alloc_error - Allocation error
 *
 * @buffer: buffer to check
 * Return: -1 on error.
 */
int alloc_error(char *buffer)
{
	if (!buffer)
	{
		perror("hsh: allocation error\n");
		return (-1);
	}
	else
	{
		return (0);
	}
}

/**
 * _getline - Reads an entire line from stream,
 * storing the address of the buffer containing the text into *b.
 *
 * @line: pointer to buffer containing the read text
 * @n: size of buffer
 * @stream: File to read from.
 * Return: Return the number of characters read,
 * including the delimiter character.
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	size_t bufsize = 1024, index = 0;
	int c, f = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * bufsize);
	if (check_alloc(buffer) == -1)
		return (-1);
	*line = buffer;
	while (1) /* Infinite loop for prompt*/
	{
		fflush(stdout); /* Flush the stdout in every iteration */
		c = _my_getc(); /* Read a character */
		if (c == EOF || c == '\n')
		{
			*(buffer + index) = '\0';
			if (c == EOF)
				return (-1);
			else
				return (index + 1);
		}
		else if (c == ' ')
		{
			if (f == 0)
			{
				f = 1;
				*(buffer + index) = c;
				index++;
			}
		}
		else
		{
			f = 0;
			*(buffer + index) = c;
			index++;
		}
		if (index >= bufsize) /* If the buffer is exceeded, reallocate. */
			buffer = realloc_buffer(buffer, &bufsize);
			if (!buffer)
				return (-1);
	}
}
/**
 * realloc_buffer - Reallocates the buffer when it is exceeded.
 *
 * @buffer: buffer to reallocate
 * @bufsize: size of the buffer
 * Return: Returns a pointer to the reallocated buffer.
 */
char *realloc_buffer(char *buffer, size_t *bufsize)
{
	*bufsize += 1024;
	char *new_buffer = _realloc(buffer, *bufsize - 1024, *bufsize);

	if (alloc_error(new_buffer) == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (new_buffer);
}
/**
 * check_alloc - Checks if the memory allocation is successful.
 *
 * @ptr: pointer to check
 * Return: Returns 0 on success and -1 on failure.
 */
int check_alloc(void *ptr)
{
	if (!ptr)
	{
		perror("hsh: allocation error\n");
		return (-1);
	}
	return (0);
}
