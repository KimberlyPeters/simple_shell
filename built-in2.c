#include "shell.h"

/**
  * _env - Display the environ in the shell.
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _env(__attribute__((unused)) char **arguments,
		__attribute__((unused)) char *input)
{
	int i = 0;

	while (environ[i] != 0)
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	return (1);
}
/**
  * _setenv - Set a environment variable.
  * @name: Name of the variable
  * @value: Value in the variable.
  * Return: 1 if works.
  */
int _setenv(char *name, char *value)
{
	char *temp, new_variable[1024];
	char **current_environment = environ;
	char **new_environment;
	int count = 0, i;

	if (value == NULL)
	{
		perror("hsh:");
	}
	temp = _getenv(name);
	if (temp != NULL)
	{
		_strcpy(temp, value);
	}
	else
	{
		while (current_environment[count] != NULL)
		{
			count++;
		}
		count += 2;
		new_environment = malloc(sizeof(char *) * (count + 1));
		if (new_environment == NULL)
		{
			perror("hsh:");
			return (1);
		}
		for (i = 0; i < count - 1; i++)
		{
			new_environment[i] = current_environment[i];
		}
		_strcpy(new_variable, name);
		_strcat(new_variable, "=");
		_strcat(new_variable, value);
		new_environment[i] = _strdup(new_variable);
		new_environment[i + 1] = NULL;
		environ = new_environment;
	}
	return (1);
}
/**
 * _unsetenv - Unset an environment variable.
 * @name: Name of the variable.
 * Return: 1 if works.
 */
int _unsetenv(char *name)
{
	char **current_environment = environ;
	char **new_environment;
	int count = 0, i, j;

	while (current_environment[count] != NULL)
		count++;

	new_environment = malloc(sizeof(char *) * (count));
	if (new_environment == NULL)
	{
		perror("hsh");
		return (1);
	}

	for (i = 0, j = 0; current_environment[i] != NULL; i++)
	{
		if (_strncmp(current_environment[i], name, _strlen(name)) != 0)
			new_environment[j++] = current_environment[i];
	}

	new_environment[j] = NULL;
	environ = new_environment;

	return (1);
}
