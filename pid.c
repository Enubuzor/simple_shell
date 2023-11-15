#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	pid_t pid, ppid, c_pid;
	/* getting the current process identification */
	pid = getpid();
	/*getting the parent process identification */
	ppid = getppid();
	printf("process identification is: %d\n", pid);
	printf("parent process identification is: %d\n", ppid);
	printf("*******************************************************\n");
	/* the child process */
	c_pid = fork();
	if (c_pid > 0)
	{
		printf("This is a parent process identification(PPID):\n");
		printf("child process identification (PID):%d\n", c_pid);
		printf("***********************************************************\n");
	}
	else if (c_pid == 0)
	{
		printf("This is the child process ID:\n");
		printf("parent process identification (PPID):%d\n", getppid());
		printf("current process identification (PID):%d\n", getpid());
	}
	else
	{
		perror("fork error");
		return (1);
	}
	return (0);
}
