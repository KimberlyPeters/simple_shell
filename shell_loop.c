#include "shell.h"

/**
 *shell_loop - Returns a pointer to a newly allocated space in memory
*/

void shell_loop(void)
{
	char *insert;
	char **args;
	int level;
	int interactive = 1, len;

	if (isatty(STDIN_FILENO) != 1)
		interactive = 0;

	signal(SIGINT, sigint_handler);

	do {
		if (interactive != 0)
		{
			len = _strlen("$ ");
			write(STDOUT_FILENO, "$ ", len);
		}

		insert = _read_line();
		if (insert == NULL)
			return;

		args = _split_line(input);
		if (args == NULL)
		{
			free(insert);
			return;
		}

		level = _execute(args, insert);

		free(insert);
		free(args);

	} while (level == 1);
}
