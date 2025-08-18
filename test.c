#include "main.h"

/**
 *
 *
 *
 *
 */

int main(void)
{
	char *line = NULL, *argv[1000];
	size_t len = 0;
	ssize_t read;
	int argc;

	while (1)
	{
		printf("#shellbalvin$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			break;
		}
		argc = tok_line(line, argv);
		if (argc == 0)
			continue;
		execute(argv);
	}
	free(line);
	return (0);
}
