#include "shell.h"

/**
 * _split_path - Split the line of the PATH environment variable.
 * @input_line: Line containing the paths.
 * @copy_input_line: Copy of the line containing the paths.
 * Return: An array with all paths split.
 */
char **_split_path(char *input_line, char *copy_input_line)
{
	int bufsize = 1024, position = 0;
	char **tokens;
	char *token;
	char *delim = ":\r\n\a";

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: allocation error\n");
		return (NULL);
	}

	_strcpy(copy_input_line, input_line);

	if (*copy_input_line == *delim)
	{
		*copy_input_line = '\0';
		tokens[position] = copy_input_line;
		position++;
	}
	token = _strtok(copy_input_line, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 1024;
			tokens = _realloc(tokens, bufsize - 1024, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("hsh: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
