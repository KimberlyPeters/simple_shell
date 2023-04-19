#include "shell.h"

/**
  * change_directory - Change the directory.
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int change_directory(char **arguments, __attribute__((unused)) char *input)
{

	if (arguments[1] == NULL)
	{
		if (chdir(get_environ("HOME")) != 0)
		{
			perror("hsh:");
		}
	}
	else
	{
		if (chdir(arguments[1]) != 0)
		{
			perror("hsh:");
		}
	}
	return (1);
}


/**
  * display_help - Display the help about a command.
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int display_help(__attribute__((unused)) char **arguments,
		__attribute__((unused)) char *input)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (i = 0; i < 3; i++)
	{
		write(STDOUT_FILENO, builtin_str[i], _strlen(builtin_str[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
  * exit_shell - Exit to the shell.
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if works.
  */
int exit_shell(__attribute__((unused)) char **arguments, char *input)
{
	int exit_value;

	if (arguments[1] == NULL)
		return (0);

	exit_value = _atoi(arguments[1]);

	if (exit_value < 0)
	{
		perror("hsh:");
		return (1);
	}
	else if (exit_value == 0)
	{
		return (0);
	}
	else if (exit_value >= 256)
	{
		free(input);
		free(arguments);
		exit(exit_value - 256);
	}
	else
	{
		free(input);
		free(arguments);
		exit(exit_value);
	}
}

/**
  * display_environ - Display the environ in the shell.
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int display_environ(__attribute__((unused)) char **arguments,
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
  * set_environ - Set a environment variable.
  * @name: Name of the variable
  * @value: Value in the variable.
  * Return: 1 if works.
  */
int set_environ(char *name, char *value)
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
