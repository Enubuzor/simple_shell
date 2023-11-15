#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */

int main(void)
{
	int number = 20;
	int count = 1;

	while (count <= 12)
	{
		int product = number * count;

		printf("%d * %d = %d\n", number, count,  product);
		count = count + 1;
	}

	return (0);
}
