#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: always 0 successful
 */
int main(void)
{
	fork();
	fork();
	fork();

	printf("%u my pid\n", getpid());

	return (0);
}
