#include "shell.h"
/**
  * _launch - Launch the process to be excetute.
  * @command_args: List of arguments passed from parsing.
  * Return: Always 1..
  */
int _launch(char **command_args)
{
	int status, process_id;
	int flag = 0;

	command_args = _check_path(command_args, &flag);

	if (command_args == NULL)
		return (1);

	process_id = fork();
	if (process_id == 0)
	{
		if (execve(command_args[0], command_args, environ) == -1)
		{
			perror("hsh");
		}
		if (flag == 1)
			free(command_args[0]);
		return (-1);
	}
	else if (process_id < 0)
	{
		perror("hsh");
		if (flag == 1)
			free(command_args[0]);
		return (-1);

	}
	else
	{
		do {
			waitpid(process_id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (flag == 1)
		free(command_args[0]);
	return (1);
}
