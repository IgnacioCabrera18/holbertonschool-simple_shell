#include <stdlib.h>
#include <stdio.h>

char *_which(char *token);

/**
 *
 *
 *
 *
 */

int main(int argc, char **argv)
{
	int i;
	char *found;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		found = _which(argv[i]);
		if (found)
		{
			printf("%s\n", found);
			free(found);
		}
		else
			printf("%s not found\n", argv[i]);
	}
	return (0);
}
