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

#define BUFFER_SIZE 128
#define PATH_MAX 4096

/** builtin functions */
char **_create_cmd_table(char *str, char *delim);
int _count_tokens(char *str, char *delim);
/** end builtin functions */

/** env functions */
char **_create_env_table(char **envp);
char *_getenv(const char *name);
int _setenv(char ***env, const char *name, const char *value);
void _modify_env(char **argv, char **envp);
/** end env functions */

/** strings functions */
char *_strdup(char *str);
char *_strtok(char *str, char *delim);
int _strncmp(char *s1, char *s2, int n)
int _strcmp(char *s1, char *s2)
/** end strings functions*/

/** memory allocation functions */
void free_array(char **arr);
/**end memory allocation functions */
#endif
