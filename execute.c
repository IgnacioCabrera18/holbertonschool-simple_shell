#include "main.h"

/**
 * execute - execute execve
 *
 * @argv: pointer to argv pointer
 */

void execute(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror("./shell");
		exit(1);
	}
	else if (pid > 0)
		wait(&status);
	else
	{
		perror("fork");
		exit(1);
	}
}
