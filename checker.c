#include "shell.h"
/**
 *checker- function to check if it is a builtin
 *@cmd: user i/p
 *@buf: buffer
 *Return: 1 if cmd excuted 0 if cmd is not executed or failed
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
