#include "shell.h"

/**
  * builtin_functions - Redirect to builtin functions.
  * @builtin_functions: Array of pointers to builtin functions.
  * Return: 1 if _help works, 0 if exit works.
  */

int (*builtin_functions[])(char **arguments, char *input) = {
	&change_directory,
	&display_help,
	&exit_shell,
	&display_environ,
};

/**
  * execute_builtin - Execute builtin process.
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: _launch(arguments).
  */
int execute_builtin(char **arguments, char *input)
{
	char *builtin_str[] = {"cd", "help", "exit", "env"};
	int i;

	if (arguments[0] == NULL)
		return (1);

	if (_strcmp(arguments[0], "setenv") == 0)
		return (set_environ(arguments[1], arguments[2]));

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(arguments[0], builtin_str[i]) == 0)
			return ((*builtin_functions[i])(arguments, input));
	}
	return (_launch(arguments));
}
