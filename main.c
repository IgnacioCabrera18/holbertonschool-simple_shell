#include "main.h"

/**
 * auxiliar - auxiliar comands
 *
 * @argv: arguments
 *
 * @line: pointer to line
 *
 * Return: 0
 */

int auxiliar(char **argv, char *line)
{
	if (strcmp(argv[0], "exit") == 0)
	{
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

/**
 * main - simple shell
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL, *argv[1000], *token;
	size_t len = 0;
	ssize_t read;
	int argc, linea = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#shellbalvin$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}
		argc = tok_line(line, argv);
		if (argc == 0)
		{
			linea++;
			continue;
		}
		auxiliar(argv, line);
		if (argv[0][0] == '/' || (argv[0][0] == '.' && argv[0][1] == '/'))
			token = argv[0];
		else
			token = _which(argv[0]);
		if (token == NULL)
		{
			printf("./hsh: %d: %s: not found\n", linea, argv[0]);
			linea++;
			continue;
		}
		execute(argv, token);
		linea++;
	}
	free(line);
	return (0);
}
