#include "shell.h"


/**
 * main - Simple shell
 * @argc: argument count
 * @argv: argument values vector.
 * Return: Always 0.
 */

int main(__attribute__((unused)) int argc,
__attribute__((unused)) char **argv)
{
	shell_loop();

	return (0);
}
