#include "main.h"

/**
 * execute - execute execve
 *
 * @argv: pointer to argv pointer
 *
 * @token: pointer to token
 */

void execute(char **argv, char *token)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(token, argv, environ);
		perror("./shell");
		exit(1);
	}
	else if (pid > 0)
		wait(&status);
	else
	{
		perror("fork");
		exit(1);
	}
}

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

/**
 * build_path - Construye la ruta completa a partir del directorio y comando
 *
 * @dir: Directorio de PATH
 *
 * @token: Comando ingresado por usuario
 *
 * @dir_tok: Buffer donde se guarda la ruta construida
 */

void build_path(char *dir, char *token, char *dir_tok)
{
	int i = 0, j = 0;

	while (dir[i] != '\0')
	{
		dir_tok[i] = dir[i];
		i++;
	}
	dir_tok[i] = '/';
	i++;
	while (token[j] != '\0')
	{
		dir_tok[i] = token[j];
		i++;
		j++;
	}
	dir_tok[i] = '\0';
}

/**
 * _which - Funcion que busca el comando ingresado
 *
 * @token: Texto ingresado por el usuario
 *
 * Return: Puntero al comando si lo encuentra
 */

char *_which(char *token)
{
	char *ruta, *ruta_cp, *dir, *dir_tok;
	struct stat st;
	size_t len;

	ruta = getenv("PATH");
	if (ruta == NULL)
		return (NULL);

	ruta_cp = strdup(ruta);
	if (ruta_cp == NULL)
		return (NULL);
	dir = strtok(ruta_cp, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + strlen(token) + 2;
		dir_tok = malloc(len);
		if (dir_tok == NULL)
		{
			free(ruta_cp);
			return (NULL);
		}
		build_path(dir, token, dir_tok);
		if (stat(dir_tok, &st) == 0)
		{
			free(ruta_cp);
			return (dir_tok);
		}
		free(dir_tok);
		dir = strtok(NULL, ":");
	}
	free(ruta_cp);
	return (NULL);
}

/**
 * print_env - print the env
 *
 * decription: print the env
 */

void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
