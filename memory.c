#include "shell.h"

/**
 * bfree - fress a pointer and NULL
 * @ptr: pointer
 *
 * Return: 1 otherwise 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0)
}
