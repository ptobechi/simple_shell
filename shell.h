#ifndef _MAIN_H
#define _MAIN_H

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

#define BUFFER_SIZE 128
#define PATH_MAX 4096

extern char **environ;

#ifndef PATH_LIST
#define PATH_LIST
/**
 * struct path_list - path linked list
 * @path: cmd path
 * @next: points to the next node
 *
 * Description: linked list node structure
 */
typedef struct path_list
{
	char *path;
	struct path_list *next;
} p_ll;
#endif

/** shell.c functions*/
void exec_shell(char **_argv, char **env, char **lineptr);
void run_cmd(char **_argv, char **envp);
/** end shell.c functions*/

/** builtin functions */
char **_create_cmd_table(char *str, char *delim);
int _count_tokens(char *str, char *delim);
char *get_cmd_path(char *cmd, int *flag);
/** end builtin functions */

/** env functions */
char **_create_env_table(char **envp);
char *_getenv(char *name);
int _setenv(char ***env, const char *name, const char *value);
void _modify_env(char **argv, char **envp);
void _printenv(char **env);
/** end env functions */

/** strings functions */
char *_strdup(char *str);
char *_strtok(char *str, char *delim);
int _strncmp(char *s1, char *s2, char n);
int _strcmp(char *s1, char *s2);
size_t _strlen(const char *str);
char *_strcat(char *dest, char *src);
char *_rm_newline_char(char *s);
int _atoi(char *s);
void _trim(char **str);
void rm_trailing_space(char *s);
/** end strings functions*/

/** memory allocation functions */
void free_array(char **arr);
void _free_linked_list(p_ll *head);
/**end memory allocation functions */
#endif
