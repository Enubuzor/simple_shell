#include "main.h"

/*
 * main - 
 * @c
 * Return: successful 0
 */
int main(void)
{
	char *prompt = "<simple_shell>$ ", *buffer;
	size_t size = 0;
	ssize_t num_chars;

	while (1)
	{
		/* display prompt */
		printf("%s", prompt);
		/* read user's command */
		num_chars = getline(&buffer, &size, stdin);
		
		if (num_chars == -1)
		{
			perror("getline"); 
			printf("Exiting <simple_shell>$ ......\n");
			free(buffer); /*free memory before returning*/
			return (-1);
		}

		printf("%s\n", buffer);
	}
	free(buffer);
	
	return (0);
}
