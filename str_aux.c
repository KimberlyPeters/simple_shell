#include "shell.h"
/**
 * _strlen - Find the length of a string.
 * @s: string.
 * Return: length of the string.
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: string.
 * @src: string.
 *
 * Return: Strings concatenated.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int dest_length = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];
	}
	dest[dest_length + i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compare two strings.
 * @str1: string.
 * @str2: string.
 * Return: number < 0 if string 1 is less than string 2
 *         number = 0 if string 1 is equal to string 2
 *         number > 0 if string 1 is bigger than string 2
 */
int _strcmp(char *str1, char *str2)
{
	int index = 0;

	while (str1[index] != '\0' && str2[index] != '\0')
	{
		if (str1[index] != str2[index])
		{
			return (str1[index] - str2[index]);
		}
		index++;
	}
	return (0);
}


/**
 * _strcpy - Copy a string.
 * @dest: array.
 * @src: string.
 *
 * Return: The copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int j, index = 0;

	while (*(src + index) != '\0')
	{
		index++;
	}

	for (j = 0; j <= index; j++)
	{
		*(dest + j) = *(src + j);
	}

	dest[j + 1] = '\0';
	return (dest);
}
/**
 * _strncmp - String comparison.
 * @str1: string 1
 * @str2: string 2
 * @n: number of bytes
 *
 * Return: 0 if equal, difference if different.
 */
int _strncmp(const char *str1, const char *str2, int n)
{
	unsigned char char1 = '\0';
	unsigned char char2 = '\0';
	int n_quotient = 0;

	if (n >= 4)
	{
		n_quotient = n >> 2;
	do {
		char1 = (unsigned char)*str1++;
		char2 = (unsigned char)*str2++;
		if (char1 == '\0' || char1 != char2)
			return (char1 - char2);
		char1 = (unsigned char)*str1++;
		char2 = (unsigned char)*str2++;
		if (char1 == '\0' || char1 != char2)
			return (char1 - char2);
		char1 = (unsigned char)*str1++;
		char2 = (unsigned char)*str2++;
		if (char1 == '\0' || char1 != char2)
			return (char1 - char2);
		char1 = (unsigned char)*str1++;
		char2 = (unsigned char)*str2++;
		if (char1 == '\0' || char1 != char2)
			return (char1 - char2);
	} while (n_quotient-- > 0);
	}
	while (n > 0)
	{
		char1 = (unsigned char)*str1++;
		char2 = (unsigned char)*str2++;
		if (char1 == '\0' || char1 != char2)
			return (char1 - char2);
		n--;
	}
	return (0);
}
