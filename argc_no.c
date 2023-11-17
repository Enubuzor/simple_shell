#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i;

	printf("argv content is argv[]\n");

	for (i = 0; i < argc; i++)
	{
		printf("argv = %s\n", argv[i]);
	}

	return (0);
}
