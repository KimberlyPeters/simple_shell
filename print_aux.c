#include "shell.h"

/**
 * _puts - print like puts function
 * @str: pointer to a char
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _atoi - Change a string to a integer.
 * @s: String.
 * Return: Integer into the string.
 */
int _atoi(char *s)
{
	int i = 0, sign = 0, num = 1;
	unsigned int power = 1, sum = 0;

	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && sign == 0)
		{
			if (s[i] == '-')
			{
				num *= -1;
			}
			else
			{
				num *= 1;
			}
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			sign = 1;
		}
		else if (sign)
		{
			break;
		}

		i++;
	}

	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		sum += (s[i] - '0') * power;
		power *= 10;
		i--;
	}

	return (sum * num);
}
