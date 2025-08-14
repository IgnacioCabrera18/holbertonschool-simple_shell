#include <stdio.h>
#include <stdlib.h>
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
	pid_t pid;
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 1; i <= 5; i++)
	{
		pid = getpid();
		printf("PID del Proceso Hijo: %u\n", pid);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{

			execve(argv[0], argv, environ);
			perror("execve");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
