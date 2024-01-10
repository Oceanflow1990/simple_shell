#include "shell.h"

/**
 * list_len -determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of stringsof the list->str
 * @head: pointer
 *
 * Return: array of string
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = listlen(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	str = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		str[i] = str;
	}
	str[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - return node whose string starts withprefix
 * @node: pointer
 * @prefix: match
 * @c: character
 *
 * Return: matc nodeor null
 */

list_t *node_starts_with(list_t *node, char  *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer
 * @node: node pointer
 *
 * Return: index of nodeor -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

