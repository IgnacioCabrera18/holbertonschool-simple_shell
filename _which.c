#include "main.h"

/**
 * _which - Funcion que busca el comando ingresado
 * @token: Texto ingresado por el usuario
 *
 * Return: Puntero al comando si lo encuentra.
 */

char *_which(char *token)
{
	char *ruta, *ruta_cp, *dir, *dir_tok;
	struct stat st;
	size_t len;
	int i = 0, j = 0;

	ruta = getenv("PATH");
	if (ruta == NULL)
		return (NULL);

	ruta_cp = strdup(ruta);
	if (ruta_cp == NULL)
		return (NULL);

	dir = strtok(ruta_cp, ":");

	while (dir != NULL)
	{
		i = 0;
		j = 0;
		len = strlen(dir) + strlen(token) + 2;
		dir_tok = malloc(len);
		if (dir_tok == NULL)
		{
			free(ruta_cp);
			return (NULL);
		}
		while (dir[i] != '\0')
		{
			dir_tok[i] = dir[i];
			i++;
		}
		dir_tok[i] = '/';
		i++;
		while (token[j] != '\0')
		{
			dir_tok[j] = token[j];
			i++;
			j++;
		}
		dir_tok[i] = '\0';
		if (stat(dir_tok, &st) == 0)
		{
			free(ruta_cp);
			return (dir_tok);
		}
		free(ruta_cp);
		return (NULL);
	}
}
