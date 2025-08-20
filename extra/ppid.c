#include "main.h"

/**
 * main - PID
 *
 * Return: Alweys 0.
 */

int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}
