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
			/*check for end of file (Ctrl+D)*/
			if (feof(stdin))
			{	
				printf("Exiting <simple_shell>$ ......\n");
				free(buffer); /*free memory before returning*/
				return (0);
			}
			/* handle other error*/
			else
			{
				perror("getline");
				free(buffer);
				return (-1);
			}
		}
		/*remove the newline character from the command*/
		if (buffer[num_chars -1] == '\n')
		{
			buffer[num_chars -1] = '\0';
		}

		printf("%s\n", buffer);
	}
	free(buffer);
	
	return (0);
}
