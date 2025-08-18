#include "main.h"

/**
 * build_path - Construye la ruta completa a partir del directorio y comando
 * @dir: Directorio de PATH
 * @token: Comando ingresado por usuario
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
		build_path(dir,token, dir_tok);
		if (stat(dir_tok, &st) == 0)
		{
			free(ruta_cp);
			return(dir_tok);
		}
		free(dir_tok);
		dir = strtok(NULL, ":");
	}
	free(ruta_cp);
	return(NULL);
}
