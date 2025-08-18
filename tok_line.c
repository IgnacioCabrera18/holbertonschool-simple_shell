#include "main.h"

/**
 * tok_line - tokenize the lines
 *
 * @line: pointer to line
 *
 * @argv: pointer to argv pointer
 *
 * Return: i
 */

int tok_line(char *line, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(line, " \t\n");
	while (token && i < 999)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	return (i);
}
