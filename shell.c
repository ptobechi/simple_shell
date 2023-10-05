#include "shell.h"

/**
 * main - Simple shell program entry point
 * @argc: argument count
 * @argv: argument variable
 * @envp: environment pointer
 *
 * Return: Always (0) Success
 */
int main(int argc, char **argv, char **envp)
{
	char *lineptr = NULL, **_argv = NULL, *delim = " ";
	size_t n = 0;
	ssize_t vread;
	/** creates an environment table for the shell procees*/
	char **env = envp;
	(void)argv;

	if (argc > 1)
		printf("Execute from file\n");

	/**signal(SIGINT, handle_signal);*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "ghst$ ", 6);
			fflush(stdout);
		}

		/** handle EOF and ctrl D */
		vread = getline(&lineptr, &n, stdin);
		if (vread == -1)
			break;

		/** handle tokenization and cmd table */
		_argv =	_create_cmd_table(lineptr, delim);

		/** enter shell mode */
		exec_shell(_argv, env, &lineptr);
	}

	free(lineptr);

	return (0);
}

/**
 * exec_shell - takes cmd from terminal
 * @_argv: command table
 * @env: environment pointer
 * @lineptr: getline read text refrence
 *
 * Return: void
 */
void exec_shell(char **_argv, char **env, char **lineptr)
{
	int exit_status = 0;

	/** handle exit*/
	if (_strncmp(_argv[0], "exit", '\0') == 0)
	{
		if (_argv[1] != NULL)
			exit_status = _atoi(_argv[1]);
		free(*lineptr), free_array(_argv), free_array(env);
		exit(exit_status);
	}
	else if (_strncmp(_argv[0], "env", '\0') == 0)
		/** prints environment variable */
		_printenv(env);
	else if (_strncmp(_argv[0], "cd", '\0') == 0)
		printf("cd dir\n");
	else if (_strncmp(_argv[0], "setenv", '\0') == 0)
		_modify_env(_argv, env);
	else
		/** execute command */
		run_cmd(_argv, env);

	free_array(_argv);
}

/**
 * run_cmd - execute cmd
 * @_argv: array of null terminated strings
 * @envp: environment variables
 *
 * Return: void
 */
void run_cmd(char **_argv, char **env)
{
	int status, handle_flag = 0;
	pid_t child_p;
	char *cmd_path;

	/** get command location*/
	cmd_path = get_cmd_path(_argv[0], &handle_flag);
	/**if (_argv[1] != NULL)
	  {
	  _env = _check_for_path(_argv[1], '$');

	  if (_env != NULL)
	  {
	  env_path = _getenv(_env);
	  if (env_path != NULL)
	  write(STDOUT_FILENO, env_path, _strlen(env_path));
	  }
	  }*/

	if (cmd_path == NULL)
	{
		free(cmd_path);
		/**_err_msg("./hsh: 1", _argv[0], " not found\n");*/
		printf("not found\n");
		exit(127);
	}
	else
	{
		child_p = fork();
		if (child_p == 0)
		{
			if (execve(cmd_path, _argv, env) == -1)
				perror((char *)EACCES);
		}

		if (handle_flag)
			free(cmd_path);
	}

	/* parent process*/
	waitpid(child_p, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(2);

}

