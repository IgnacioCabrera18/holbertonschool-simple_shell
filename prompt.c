#include "main.h"

/**
 * main - prompt
 *
 * Return: Alweys 0.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("#shellbalvin$ ");

	read = getline(&line, &len, stdin);

	if (read != -1)
		printf("%s", line);
	else
		perror("Error reading input");

	free(line);
	return (0);
}
