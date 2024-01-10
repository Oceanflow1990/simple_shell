#include "shell.h"

/**
 * _memset - fills memory with a constantbyte
 * @s: pointer to memory
 * @b: byre fill *s
 * @n: amount of byte to pass
 *
 * Return: (s) a pointer to the memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @strs: string of strings
 */

void ffree(char **strs)
{
	char **a = strs;

	if (!strs)
		return;
	while (*strs)
		free(*strs++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previou malloc block
 * @old_size: byte sieofprevious block
 * @new_size: new block
 *
 * Return: pointer to ...........
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (0);
}
