#include <stdio.h>
#include <string.h>

/**
 *
 *
 *
 *
 */

int main()
{
	char str[] = "Ejercicio de tokens", delimitar[] = " ", *token;

	token = strtok(str, delimitar);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delimitar);
	}

	return (0);
}
