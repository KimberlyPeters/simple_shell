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
		if (chdir(_getenv("HOME")) != 0)
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
 * test_exit_builtin - Tests the exit built-in.
 *
 * Return: 0 if successful, 1 otherwise.
 */
int test_exit_builtin(void)
{
	char *argv[] = {"exit", NULL};
	int status;

	status = exit_shell(argv, NULL);
	if (status == 0)
		return (0);
	else
		return (1);
}
