#include "shell.h"

/**
 * _file_input - execute command from file
 * @argv: file path
 * @env: eviron variable
 *
 * Return: Always (0) Success
 */
int _file_input(char **argv, char **env)
{
	char command[1000], **env_var = NULL;
	int fd;
	ssize_t bytes_read;

	if (access(argv[1], R_OK) != 0)
	{
		err_msg(argv[0], "Can't open ", argv[1]);
		exit(127);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror((char *)EACCES);
		exit(127);
	}

	env_var = _create_env_table(env);
	while ((bytes_read = read(fd, command, sizeof(command))) > 0)
	{
		pid_t child_p = fork();

		if (child_p == -1)
		{
			perror("Error creating process");
			return (1);
		}

		if (child_p == 0)
		{
			char *args[] = {"/bin/sh", "-c", NULL, NULL};

			command[bytes_read] = '\0';
			args[2] = command;
			run_cmd(args, env_var);

		}
	}

	free_array(env_var), close(fd), exit(0);
	return (0);
}
