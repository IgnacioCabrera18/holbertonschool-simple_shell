#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/**
 *
 *
 *
 *
 */

int main()
{
	char *line = NULL, *token, *argv[2];
	size_t len = 0 ;
	ssize_t read;
	pid_t pid;
	int status;

	while (1)
	{
		printf("#minishell$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		if (line[0] == '\0')
			continue;

		token = strtok(line, " ");
		if (token == NULL)
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			argv[0] = token;
			argv[1] = NULL;

			execve(token, argv,environ);
			perror("execve");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
