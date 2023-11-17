#include <stdio.h>
#include <stdlib.h>

char *readcommand(void);

/**
 * readcommand - reads user input from the stdin jin a loop
 *
 * Return: Always returns NULL
 */
char *readcommand(void)
{
	char *prompt = "<simple_shell>$";
	char *buffer = NULL;
	size_t size = 0;
	ssize_t num_chars;

	while (1)
	{
		printf("%s", prompt);/*display prompt*/
		num_chars = getline(&buffer, &size, stdin);/*read user's command*/

		if (num_chars == -1)
		{
			if (feof(stdin))/*check for end of file(Ctrl D)*/
			{
				printf("Exiting <simple_shell>$......\n");
				free(buffer);
				return (NULL);
			}
			else /*handle other error*/
			{
				perror("getline failed");
				free(buffer);
				return (NULL);
			}
		}
		printf("%s\n", buffer);
	}
	free(buffer);

	return (NULL);
}

/**
 * main - entry point
 *
 * Return: always 0 on success
 */
int main(void)
{
	readcommand();
	return (0);
}
