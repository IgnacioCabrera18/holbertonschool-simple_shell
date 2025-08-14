#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/**
 *
 *
 *
 *
 */

int mini_shell()
{
	pid_t pid;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token, limite[] = " ";

	while (1)
	{
		printf("minishell$ ");

		read = getline(&line, &len, stdin);

		token = strtok(line, limite);

		pid = fork();

		if (pid == 0)
		{
			execve(token[0], token, environ);
			exit(1);
		}
	}
}
