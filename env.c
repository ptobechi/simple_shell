#include "shell.h"

/**
 * _create_env_table - create a custom env command table
 * @envp: environment variable
 *
 * Return: Returns a pointer
 */
char **_create_env_table(char **envp)
{
	int count = 0, i;
	char **env;

	/*Count the number of environment variables*/
	while (envp[count] != NULL)
		count++;

	/* Allocate memory for the array of environment variables*/
	env = (char **)malloc((count + 1) * sizeof(char *));
	if (env == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	memset(env, 0, (count + 1));

	/* Copy each environment variable to the new array*/
	for (i = 0; i < count; i++)
	{
		env[i] = _strdup(envp[i]);
		if (env[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}
	}
	/* Add a NULL terminator to the end of the array*/
	env[count] = NULL;

	return (env);
}

/**
 * _getenv - get environment variable
 *
 * @name: Environment path
 *
 * Return: Always 0 (Sucess)
 */
char *_getenv(char *name)
{
	int i = 0, j = 0, k = 0;
	char *val = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, '=') == 0)
		{
			while (name[++j] != '\0')
				;

			while (environ[i][++k] != '\0')
				;

			val = malloc((k - j) * sizeof(char));
			if (val == NULL)
				return (NULL);

			for (k = 0, j++; environ[i][j] != '\0'; j++, k++)
				val[k] = environ[i][j];

			val[k] = '\0';
			break;
		}
	}
	return (val);
}

/**
 * _setenv - set an environment variable
 * @env: pointer to the environment variable table
 * @name: name of the variable to set
 * @value: value to assign to the variable
 *
 * Return: Returns 0 on success, 1 on failure
 */
int _setenv(char ***env, const char *name, const char *value)
{
	int count = 0;
	char *new_var, **new_env;

	/* Count the number of existing environment variables */
	while ((*env)[count] != NULL)
		count++;

	/* Create a new environment variable in the form "name=value" */
	new_var = (char *)malloc(_strlen(name) + _strlen(value) + 2);
	if (new_var == NULL)
	{
		perror("Memory allocation failed");
		return (1);
	}
	sprintf(new_var, "%s=%s", name, value);

	/* Reallocate memory for the environment table */
	new_env = (char **)realloc(*env, (count + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("Memory allocation failed");
		free(new_var); /* Free the newly allocated variable */
		return (1);
	}

	/* Update the env table with the new var and NULL terminator */
	*env = new_env;
	(*env)[count] = new_var;
	(*env)[count + 1] = NULL;

	return (0);
}

/**
 * _modify_env - creates or updates an environment variable
 * @_argv: array of arguments
 *
 * Return: void
 */
void _modify_env(char **argv, char **env)
{
	if (_strncmp(argv[0], "setenv", '\0') == 0)
		_setenv(&env, argv[1], argv[2]);
}

/**
 * _printenv - print environmental variables
 * @env: environment variable
 *
 * Return: void
 */
void _printenv(char **env)
{
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
