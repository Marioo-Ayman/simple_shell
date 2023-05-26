#include "shell.h"

/**
 * execution - function that executes the commands
 * @cp: copy of the command
 * @cmd: the command from the user
 * Return: nothing
 */
void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}

/**
* exit_cmd - to exit shell
* @command: command from the user
* @line: from getline
* Return: nothing
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
