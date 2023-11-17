#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: always 0 successful
 */
int main(void)
{
	pid_t child_pid;
	int status;
	int i;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	else if (child_pid == 0)
	{
		execve("/usr/bin/ls", args, NULL);
		perror("error:");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	}
}
