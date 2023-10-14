#include "shell.h"

/**
 * append_node - add a new node to a linked list
 * @head: node haed
 * @path: path to add
 *
 * Return: pointer to linked list head
 */
p_ll *append_node(p_ll *head, char *path)
{
	p_ll *new, *temp;

	new = malloc(sizeof(p_ll));
	if (new == NULL)
		return (NULL);

	new->path = path;
	new->next = NULL;

	if (head == NULL)
		head = new;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (head);
}

/**
 * create_path_ll - create linked list
 *
 * Return: void
 */
p_ll *create_path_ll(void)
{
	p_ll *head = NULL;
	char *name = "PATH", *val, **tokens, *delim = ":";
	int i;

	val = _getenv(name);

	if (val == NULL)
		return (NULL);

	tokens = _create_cmd_table(val, delim);

	for (i = 0; tokens[i] != NULL; i++)
		head = append_node(head, _strdup(tokens[i]));

	free(val);
	free_array(tokens);
	return (head);
}

/**
 * find_file - find the file
 * @file_path: path to file
 *
 * Return: 0 if found, -1 otherwise
*/
int find_file(char *file_path)
{
	struct stat st;

	if (file_path == NULL)
	{
		perror("File path is NULL");
		return (-1);
	}

	/** lookup filepath with stat*/
	if (stat(file_path, &st) < 0)
		return (-1);

	return (0);
}

/**
 * get_cmd_path - search for executable cmd
 * @cmd: command
 * @flag: handle path mode
 *
 * Return: location pointer
 */
char *get_cmd_path(char *cmd, int *flag)
{
	char *cmd_full_path, *cmd_parent_path;
	p_ll *head = NULL, *temp;

	if (cmd == NULL)
		return (NULL);

	/**if a full path or path exists return path*/
	/**if (cmd[0] == '/' || find_file(cmd) == 0)*/
	if (cmd[0] == '/' || cmd[0] == '.')
		return (cmd);

	/** create linked list from env var PATH **/
	head = create_path_ll();
	if (head == NULL)
		return (NULL);

	/** find dirs for command exec file **/
	temp = head;
	do {
		cmd_parent_path = _strcat(temp->path, "/");
		cmd_full_path = _strcat(cmd_parent_path, cmd);

		free(cmd_parent_path);
		if (find_file(cmd_full_path) == 0)
			break;

		free(cmd_full_path);
		cmd_full_path = NULL;
		temp = temp->next;

	} while (temp->next != NULL);

	_free_linked_list(head);
	*flag = 1;
	return (cmd_full_path);
}
