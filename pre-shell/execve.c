#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
 *
 *
 *
 */

int main()
{
	char *argv[] = {"/bin/echo", "Es Jorge", NULL};
	char *str = NULL;
	size_t len = 0;
	ssize_t token;
	

	printf("Adivina quien es cubano: ");
	
	while(1)
	{
		token = getline(&str, &len, stdin);
		free(str);
		execve(argv[0], argv, environ);
	}

	return (0);
}
