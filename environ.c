#include "shell.h"

/**
 * _myenv - printsthe current environment
 * @info: argument
 *
 * Return: 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - get thevalue of an environ variable
 * @info: argument
 * @name: variable name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - intializenew environment variable
 * @info: argument
 *
 * Return: 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("incorrect no. of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[i], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - resume an environment var
 * @info: argument
 *
 * Return: 0
 */

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n")
			return (1);
	}
	return (0);
}

/**
 * populate_env_list - populate env linkedlist
 * @info: argument
 *
 * Return: 0
 */

int populate_env_list(info *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
