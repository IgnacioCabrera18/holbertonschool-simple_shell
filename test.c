#include "main.h"

/**
 *
 *
 *
 *
 */

int main(void)
{
	char *line = NULL, *argv[1000], *token;
	size_t len = 0;
	ssize_t read;
	int argc, linea = 1;

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
		{
			linea++;
			continue;
		}
		if (argv[0][0] == '/' || (argv[0][0] == '.' && argv[0][1] == '/'))
			token = argv[0];
		else
			token = _which(argv[0]);
		if (token == NULL)
		{
			fprintf(stderr, "sh: %d: %s: not found\n", linea, argv[0]);
			linea++;
			continue;
		}
		execute(argv, token);
	}
	free(line);
	return (0);
}
