#include "shell.h"

/**
 * add_node - Funct. to  add a node to the start of the list
 * @h: address of pointer to the head node
 * @s: str field
 * @n: node index
 *
 * Return: size of list
 */

list_t *add_node(list_t **h, const char *s, int n)
{
	list_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->n = n;
	if (s)
	{
		new_head->s = _strdup(s);
		if (!new_head->s)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * add_node_end - adds anode to the end of the list
 * @h: address pointer
 * @s: str field of hole
 * @n: nodeindex .......
 * Return: size of list
 */

list_t *add_node_end(list_t **h, const *s, int n)
{
	list_t *new_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->n = n;
	if (s)
	{
		new_node->s = _strdup(s);
		if (!new_node->s)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		h = new_node;
	return (new_node);
}

/**
 * print_list_str - print only the str element of a linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (1);
}

/**
 * delete_node_at_index - delete node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 otherwise 0
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - free all node of a list
 * @head_ptr: pointer
 *
 * Return: void
 */

void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
