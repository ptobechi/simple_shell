#include "shell.h"

/**
 * _strcat - concat two strings
 * @dest: destination string
 * @src: src string
 *
 * Return: result of dest + src
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	char *str;

	while (dest[++i] != '\0')
		;

	while (src[++j] != '\0')
		;

	i++;

	str = malloc((i + j + 1) * sizeof(char));

	for (i = 0; dest[i] != '\0'; i++)
		str[i] = dest[i];

	for (j = 0; src[j] != '\0'; i++, j++)
		str[i] = src[j];

	str[i] = '\0';

	return (str);
}

/**
 * _strncmp - compare two string up to a char in s1
 * @s1: string 1
 * @s2: string 2
 * @c: char to compare up to
 *
 * Return: 0 if equal, pos int if s1 > s2, neg int if s1 < s2
 */
int _strncmp(char *s1, char *s2, char c)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (s1[i] != c)
	{
		if ((s1[i]) > (s2[i]))
			return ((s1[i]) - (s2[i]));
		if ((s1[i]) < (s2[i]))
			return ((s1[i]) - (s2[i]));
		i++;
	}
	return (0);
}

/**
 * _strdup - dub
 * @s: string
 *
 * Return: Always 0
 */
char *_strdup(char *s)
{
	char *s_dup;
	int i = 0;

	while (s[i++] != '\0')
		;

	s_dup = malloc(i * sizeof(char));
	if (s_dup == NULL)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		s_dup[i] = s[i];

	s_dup[i] = '\0';

	return (s_dup);
}

/**
 * _strndup - dup and return a new string
 * @start: starting point
 * @end: end of string dup
 * @s: string
 *
 * Return: pointer to a new string
 */
char *_strndup(char *s, int start, int end)
{
	char *s_dup;
	int i = 0;

	while (s[++i] != '\0')
		;

	if (start > i || end > i || start >= end)
		return (NULL);

	i = (end + 2) - start;

	s_dup = malloc(i * sizeof(char));
	if (s_dup == NULL)
		return (NULL);

	for (i = 0; start <= end; i++, start++)
		s_dup[i] = s[start];

	s_dup[i] = '\0';

	return (s_dup);
}

/**
 * _strlen  - calculate length of a string
 * @str: string
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
