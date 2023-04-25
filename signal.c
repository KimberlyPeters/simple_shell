#include "shell.h"

/**
 * sigint_handler - Signal handler.
 * @signal: The signal that triggered the handler.
 */
void sigint_handler(int signal)
{
	(void)signal;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
