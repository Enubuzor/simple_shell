#include "main.h"

/*
 * main -
 * @c
 * Return: successful 0
 */
int main(int argc, char *argv[])
{
	const char *delim = (argc > 1) ? argv[1] : " ";
	char *prompt = "<simple_shell>$ ", *buffer, *token;
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
		if (buffer[num_chars - 1] == '\n')
		{
			buffer[num_chars - 1] = '\0';
		}
		/* tokenization of input */
		token = strtok(buffer, delim);

		while (token != NULL)
		{
			/* process each command */
			printf("%s\n", token);

			/*get the next token*/
			token = strtok(NULL, delim);
		}
		/*printf("%s\n", buffer);*/

		/* fork and execute command */
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork failed");
			free(buffer);
			return (-1);
		}
		else if (pid == 0)
		{
			/* using execve to execute command*/
			if (execve(buffer, (char *[]){buffer, NULL}, NULL) == -1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);/*wait fot the child process to complete*/
		}
	}

	free(buffer);

	return (0);
}
