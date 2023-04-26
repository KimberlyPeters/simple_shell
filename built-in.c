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
 * exit_shell - Exit the shell.
 * @arguments: List of arguments passed from parsing.
 * @input: Input line for free.
 * Return: Always returns 0 to exit the shell.
 */
int exit_shell(char **arguments, char *input)
{
	free(input);
	free(arguments);
	exit(EXIT_SUCCESS);
	return (0);
}
