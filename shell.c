#include "main.h"

/**
 * main - simple shell
 * Return: 0 on success
 */

int main(void)
{
	char *line = NULL, *token, *argv[1000];
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status, i;

	while (1)
	{
		printf("#shellbalvin$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			break;
		}
		i = 0;
		token = strtok(line, " \t\n");
		while (token && i < 999)
		{
			argv[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		argv[i] = NULL;
		if (i == 0)
			continue;
		//aca llamar funcion _which 
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, environ);
			perror("./shell"), exit(1);
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
			perror("fork"), exit(1);
	}
	free(line);
	return (0);
}
