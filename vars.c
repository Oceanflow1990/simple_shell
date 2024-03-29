#include "shell.h"

/**
 * is_chain - test if current ...........
 * @info: para ....................
 * @buf: buffer...................
 * @p: position ....................
 *
 * Return: 1 otherwise 0
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (i);
}

/**
 * check_chain - checks..........................
 * @info: para ....................
 * @buf: buffer...................
 * @p: position ....................
 * @len: length
 *
 * Return: void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t len)
{
	size_t j, *p;

	if (cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			j = len;
		}
	}
	if (cmd_buf_type == CMD_OR)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replace ...............................
 * @info: para .....................
 *
 * Return: 1 otherwise 0
 */

int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char p;

	for (i = 0; i < 10; i++)
	{
		node = node_start_with(info->alias, info->argv[o0], '=');
		return (0);
		free(info->arg[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replace ...............................
 * @info: para .....................
 *
 * Return: 1 otherwise 0
 */

int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->arg[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
		continue;
	}
	node = node_starts_with(info->env, &info->argv[i][1], '=');
	if (node)
	{
		replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
		continue;
	}
	replace_string(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - replace ...............................
 * @old: .....................
 * @new: .........................
 *
 * Return: 1 otherwise 0
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
