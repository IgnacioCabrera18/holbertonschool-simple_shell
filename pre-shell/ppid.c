#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int get_ppid(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}
