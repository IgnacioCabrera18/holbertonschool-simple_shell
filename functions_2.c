#include "main.h"

/**
 * get_path_from_env - Gets the PATH variable from the environment
 *
 * Return: Pointer to the value of PATH, or NULL if not found
 */

char *get_path_from_env(void)
{
	int i = 0;
	char *env;

	while (environ[i] != NULL)
	{
		env = environ[i];

		if (env[0] == 'P' && env[1] == 'A' && env[2] == 'T' &&
		env[3] == 'H' && env[4] == '=')
			return (env + 5);
		i++;
	}
	return (NULL);
}
