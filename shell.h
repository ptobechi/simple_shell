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
#endif

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
#ifndef _EXEC_SHELL_H
#define _EXEC_SHELL_H
void exec_shell(char **_argv, char **env, char **lineptr);
#endif

#ifndef _RUN_CMD_H
#define _RUN_CMD_H
void run_cmd(char **_argv, char **envp);
#endif
/** end shell.c functions*/

/** builtin functions */
#ifndef _CREATE_CMD_TABLE_H
#define _CREATE_CMD_TABLE_H
char **_create_cmd_table(char *str, char *delim);
#endif

#ifndef _COUNT_TOKENS_H
#define _COUNT_TOKENS_H
int _count_tokens(char *str, char *delim);
#endif

#ifndef _GET_CMD_PATH_H
#define _GET_CMD_PATH_H
char *get_cmd_path(char *cmd, int *flag);
#endif
/** end builtin functions */

/** env functions */
#ifndef _CREATE_ENV_TABLE_H
#define _CREATE_ENV_TABLE_H
char **_create_env_table(char **envp);
#endif

#ifndef _GETENV_H
#define _GETENV_H
char *_getenv(char *name);
#endif

#ifndef _SETENV_H
#define _SETENV_H
int _setenv(char ***env, const char *name, const char *value);
#endif

#ifndef _MODIFY_ENV_H
#define _MODIFY_ENV_H
void _modify_env(char **argv, char **envp);
#endif

#ifndef _PRINTENV_H
#define _PRINTENV_H
void _printenv(char **env);
#endif
/** end env functions */

/** strings functions */
#ifndef _STRDUP_H
#define _STRDUP_H
char *_strdup(char *str);
#endif

#ifndef _STRTOK_H
#define _STRTOK_H
char *_strtok(char *str, char *delim);
#endif

#ifndef _STRNCMP_H
#define _STRNCMP_H
int _strncmp(char *s1, char *s2, char c);
#endif

#ifndef _STRCMP_H
#define _STRCMP_H
int _strcmp(char *s1, char *s2);
#endif

#ifndef _STRLEN_H
#define _STRLEN_H
size_t _strlen(const char *str);
#endif

#ifndef _STRCAT_H
#define _STRCAT_H
char *_strcat(char *dest, char *src);
#endif

#ifndef _RM_NEWLINE_CHAR_H
#define _RM_NEWLINE_CHAR_H
char *_rm_newline_char(char *s);
#endif

#ifndef _ATOI_H
#define _ATOI_H
int _atoi(char *s);
#endif

#ifndef _TRIM_H
#define _TRIM_H
void _trim(char **str);
#endif

#ifndef _RM_TRAILING_SPACE_H
#define _RM_TRAILING_SPACE_H
void rm_trailing_space(char *s);
#endif
/** end strings functions*/

/** memory allocation functions */
#ifndef _FREE_ARRAY_H
#define _FREE_ARRAY_H
void free_array(char **arr);
#endif

#ifndef _FREE_LINKED_LIST_H
#define _FREE_LINKED_LIST_H
void _free_linked_list(p_ll *head);
#endif
/**end memory allocation functions */
