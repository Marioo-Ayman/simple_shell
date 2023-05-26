#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* built ins */
int checker(char **cmd, char *buf);
void prompt_user(void);
void handle_signal(int m);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

void print_env(void);

/* tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);
char **tokenizer(char *line);

/* strings */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);

/* my own getline */
ssize_t _getline(char **line, size_t *n);

/**
 * struct builtin - contain the builtins
 * @env: the environments variable
 * @exit: for exit command
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct info - for informations about functions
 * @final_exit: for the last command
 * @ln_count: counter
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct flags - containging the flags
 * @interactive: check whether it's interactive or not
 */
struct flags
{
	bool interactive;
} flags;

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

#endif /* SHELL_H */
