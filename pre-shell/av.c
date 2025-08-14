#include "main.h"
#include <stdio.h>

/**
 *
 *
 *
 *
 */

int main(int ac, char **av)
{
	int i;

	(void)ac;

	for (i = 0; av[i]; i++)
	{
		printf("In the posicion %d The argument is: %s.\n", i, av[i]);
	}
	return (0);
}
