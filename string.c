#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string whoselength to check
 *
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - perform lexicogarphic comparison
 * @s1: first string
 * @s2: seconstring
 *
 * Return: negative is s1 positive if s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with heystack
 * @heystack: string to search
 * @nidle: the subsr
 *
 * Return: next char of heystack
 */

char *starts_with(const char *heystack, const char *nidle)
{
	while (*nidle)
		if (*nidle++ != *heystack)
			return (NULL);
	return ((char *)heystacck);
}

/**
 * _strcat - concatenate two strings
 * @d: the destination buffer
 * @s: source buffer
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *d, char *s)
{
	char *ret = d;

	while (*d)
		d++;
	while (*s)
		*d++ = *s++;
	*d = *s
		return (ret);
}
