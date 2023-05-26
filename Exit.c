#include "shell.h"

/**
* exit_cmd - to exit shell
* @command: cmd
* @line: i/p of stdin
*
* Return: nothing
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
