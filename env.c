#include "shell.h"

/**
<<<<<<< HEAD
* print_env - prints the environment string
=======
* print_env - prints the string of env
>>>>>>> 8453623dc19b5d0b21f30954542703c33ee501ab
*
*/
void print_env(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
