#include "shell.h"

/**
 * get_environ - Find a variable in all environment variables.
 * @var_name: Name of the environment variable.
 * Return: All the content into the environment variable.
 */
char *get_environ(const char *var_name)
{
	size_t var_len;
	char **env_var;

	/* Get var_name length */
	var_len = _strlen((char *)var_name);

	if (environ == NULL || var_name[0] == '\0')
		return (NULL);

	var_len--;
	for (env_var = environ; *env_var != NULL; env_var++)
	{
		if (!_strncmp(*env_var, var_name, var_len) && (*env_var)[var_len + 1] == '=')
			return (&(*env_var)[var_len + 2]);
	}
	return (NULL);
}
