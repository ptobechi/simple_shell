#include "shell.h"

/**
 * _count_tokens - count number of tokens in a str
 * @str: string of null terminated char
 * @delim: delimeter
 *
 * Return: Always (1) Success
 */
int _count_tokens(char *str, char *delim)
{
	int count = 1;

	if (str == NULL)
		return (-1);

	while (*str != '\0')
	{
		if (*str == *delim)
			count++;
		str++;
	}
	return (count);
}

/**
 * _create_cmd_table - create a command table
 * @tokens: string of null terminated char
 * @delim: delimeter
 *
 * Return: Always 0 (Success)
 */
char **_create_cmd_table(char *tokens, char *delim)
{
	char **arr = NULL, *tokens_cpy, *token;
	int arr_len, i;

	if (tokens == NULL)
		return (NULL);

	/** count number delim for array alloc*/
	arr_len = _count_tokens(tokens, delim);

	/** mem allocation for cmd table */
	arr = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (arr == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}

	/** tokenize token_cpy and store tokens to arr */
	memset(arr, 0, (arr_len + 1));
	i = 0;
	tokens_cpy = _strdup(tokens);
	token = _strtok(tokens_cpy, delim);
	while (token != NULL)
	{
		arr[i] = _strdup(_rm_newline_char(token));
		if (arr[i] == NULL)
		{
			perror("Memory allocation failed");
			free(tokens_cpy);
			free_array(arr);
			return (NULL);
		}
		token = _strtok(NULL, delim);
		i++;
	}
	arr[i] = NULL;

	free(tokens_cpy);
	return (arr);
}
