#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 *
 */

int main()
{
	char *line = NULL;
	size_t len = 0;
	//son los bytes que lee getline
	ssize_t read;

	printf("$ ");

	read = getline(&line, &len, stdin);

	if (read != -1)
		printf("%s", line);
	else
		perror("Error reading input");

	free(line);
	return (0);
}
