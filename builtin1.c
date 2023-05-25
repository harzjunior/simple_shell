#include "shell.h"

/**
* _myhistory - The history list is shown, featuring each command on an individual line
*              and accompanied by line numbers starting from 0.
* @info: Structure that holds possible arguments, intended for maintaining
*        a consistent function prototype.
*  Return: 0
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
* unset_alias - Assigns a string value to an alias.
* @info: Struct that represents a parameter.
* @str: str alias
* Return: 0 on success, otherwise 1 on error
*/
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
* set_alias - Assigns a string value to the specified alias.
* @info: Struct that represents a parameter.
* @str: str alias
*
* Return: 0 on success, otherwise 1 on error
*/
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - outputs an alias str
* @node: alias node
* Return: Always 0 on success, otherwise 1 on error
*/
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Imitates the behavior of the builtin alias command (man alias)
 * @info: Argument structure for maintaining constant function prototypes.
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
