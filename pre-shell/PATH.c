#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 *
 *
 *
 *
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
		len = strlen(dir) + 1 + strlen(token) + 1;
		dir_tok = malloc(len);
		if (dir_tok == NULL)
		{
			free(ruta_cp);
			return(NULL);
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
			dir_tok[i] = token[j];
			i++;
			j++;
		}
		dir_tok[i] = '\0';
		/*snprintf(dir_tok, len, "%s/%s", dir, token);*/

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
