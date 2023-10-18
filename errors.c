#include "shell.h"

/**
 * error_msg - custom error message
 * @erros: array of null terminated strings
 * @path: cmd path
 *
 * Return: void
 */
void error_msg(char **erros, char *path)
{
	char err[256] = ""; /* initialize err msg to empty str */
	int i, len = 0;

	/* Create the custom error message */
	for (i = 0; erros[i] != NULL; i++)
	{
		char *current = erros[i]; /* get current str in arr */

		while (*current != '\0')
		{
			err[len] = *current; /*concatenate err*/
			len++;
			current++;
		}

		/*Add a : in strings*/
		if (erros[i + 1] != NULL)
		{
			err[len] = ':';
			len++;
		}
	}
	i = 0;
	while (*path != '\0')
	{
		err[len] = path[i];
		len++;
		path++;
	}
	err[len++] = '\n';

	/* Write the error message to stderr*/
	write(STDERR_FILENO, err, len);
}

/**
 * err_msg - custom error messages
 * @a: shell (hsh)
 * @b: custom msg
 * @c: command
 *
 * Return: void
 */
void err_msg(char *a, char *b, char *c)
{
	char error_message[256];
	int len = 0;

	/* Create the custom error message*/
	while (a[len] != '\0')
	{
		error_message[len] = a[len];
		len++;
	}
	error_message[len++] = ':';
	error_message[len++] = ' ';
	error_message[len++] = '0';
	error_message[len++] = ':';
	error_message[len++] = ' ';
	while (*b != '\0')
	{
		error_message[len++] = *b;
		b++;
	}
	while (*c != '\0')
	{
		error_message[len++] = *c;
		c++;
	}
	error_message[len++] = '\n';

	/* Write the error message to stderr*/
	write(STDERR_FILENO, error_message, len);
}

/**
 * _err_msg - custom error messages
 * @a: shell (hsh)
 * @b: custom msg
 * @c: command
 *
 * Return: void
 */
void _err_msg(char *a, char *b, char *c)
{
	char error_message[256];
	int len = 0;

	/* Create the custom error message*/
	while (a[len] != '\0')
	{
		error_message[len] = a[len];
		len++;
	}
	error_message[len++] = ':';
	error_message[len++] = ' ';
	error_message[len++] = 1;
	error_message[len++] = ':';
	while (*b != '\0')
	{
		error_message[len++] = *b;
		b++;
	}
	error_message[len++] = ':';
	while (*c != '\0')
	{
		error_message[len++] = *c;
		c++;
	}
	error_message[len++] = '\n';

	/* Write the error message to stderr*/
	write(STDERR_FILENO, error_message, len);
}
