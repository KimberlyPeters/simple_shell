#include "shell.h"
/**
  * _strcspn - Find the position where the delimiter is found in the string.
  * @str: String.
  * @delimiter: Delimiter.
  * Return: the position in the string.
  */
int _strcspn(char *str, const char *delimiter)
{
	int counter = 0, i;

	while (*str)
	{
		for (i = 0; delimiter[i] != '\0'; i++)
		{
			if (*str == delimiter[i])
				return (counter);
		}
		counter++;
		str++;
	}
	return (counter);
}

/**
  * _strspn - Find the position until the delimiter is equal to the string.
  * @str: String.
  * @delimiter: Delimiter.
  * Return: the position when delimiter is different to the string.
  */
int _strspn(char *str, const char *delimiter)
{
	int i;

	for (i = 0; (str[i] == delimiter[i]) &&
			(str[i] != '\0' && delimiter[i] != '\0'); i++)
	{
		;
	}
	return (i);
}

/**
  * _strtok_r - Find the first token in a string until the delimiter
  *             and save the rest of the string in save_str.
  * @str: String.
  * @delimiter: Delimiter.
  * @save_str: The rest of the string.
  * Return: First word tokenized.
  */
char *_strtok_r(char *str, const char *delimiter, char **save_str)
{
	char *end;

	if (str == NULL)
		str = *save_str;

	if (*str == '\0')
	{
		*save_str = str;
		return (NULL);
	}

	str += _strspn(str, delimiter);

	if (*str == '\0')
	{
		*save_str = str;
		return (NULL);
	}

	end = str + _strcspn(str, delimiter);

	if (*end == '\0')
	{
		*save_str = end;
		return (str);
	}

	*end = '\0';
	*save_str = end + 1;
	return (str);
}

/**
  * _strtok - Tokenize a string in words separated by a delimiter.
  * @str: String.
  * @delimiter: Delimiter.
  * Return: Word tokenized.
  */
char *_strtok(char *str, const char *delimiter)
{
	static char *save_str;

	return (_strtok_r(str, delimiter, &save_str));
}
