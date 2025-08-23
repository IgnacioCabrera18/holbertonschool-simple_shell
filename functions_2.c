#include "main.h"

/**
 * get_path_from_env - Gets the PATH variable from the environment
 *
 * Return: Pointer to the value of PATH, or NULL if not found
 */

char *get_path_from_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * exit_and_env - auxiliar comands
 *
 * @argv: arguments
 *
 * @line: pointer to line
 *
 * Return: 0
 */

int exit_and_env(char **argv, char *line, char *token)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		if (token != NULL)
			free(token);
		free(line);
		exit(0);
	}
	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}
